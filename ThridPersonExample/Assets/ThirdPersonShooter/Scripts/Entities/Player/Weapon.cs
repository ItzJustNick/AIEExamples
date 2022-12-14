using JetBrains.Annotations;

using System.Collections;

using ThirdPersonShooter.Entities.AI;
using ThirdPersonShooter.Utilities;
using ThirdPersonShooter.VFX;

using UnityEngine;
using UnityEngine.InputSystem;

namespace ThirdPersonShooter.Entities.Player
{
	public class Weapon : MonoBehaviour
	{
		[SerializeField] private InputActionReference shootAction;
		[SerializeField] private InputActionReference reloadAction;
		[SerializeField] private Transform shootPoint;
		[SerializeField] private BulletLine bulletLine;

		[CanBeNull] private PlayerEntity player;

		private bool canShoot = true;

		public void SetPlayer(PlayerEntity _player) => player = _player;

		private void Update()
		{
			if(player != null && canShoot && shootAction.action.IsDown())
			{
				if(player.ammo <= 0)
				{
					return;
				}
				
				player.LowerAmmo();
				player.UpdateAmmoCount();
				
				bool didHit = Physics.Raycast(shootPoint.position, shootPoint.forward, out RaycastHit hit, player.Stats.Range);

				if(didHit && hit.collider.TryGetComponent(out EnemyEntity entity))
				{
					entity.Stats.TakeDamage(player.Stats.Damage);
				}

				BulletLine newLine = Instantiate(bulletLine);
				newLine.Play(shootPoint.position, didHit ? hit.point : shootPoint.position + shootPoint.forward * player.Stats.Range, didHit);
				StartCoroutine(ShootCooldown_CR());
			}
			else if(player != null && reloadAction.action.IsDown())
			{
				ReloadGun();
			}
		}

		private void ReloadGun()
		{
			player.ammo = 30;
			player.isNeedReload = false;
			player.UpdateAmmoCount();
		}

		private IEnumerator ShootCooldown_CR()
		{
			canShoot = false;

			if(player != null)
			{
				yield return new WaitForSeconds(player.Stats.AttackRate);
			}

			canShoot = true;
		}
	}
}