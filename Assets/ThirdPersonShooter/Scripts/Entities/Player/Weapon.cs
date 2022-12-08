using JetBrains.Annotations;

using System;
using System.Collections;

using ThirdPersonShooter.Entities.AI;
using ThirdPersonShooter.Utilities;

using UnityEngine;
using UnityEngine.InputSystem;

namespace ThirdPersonShooter.Entities.Player
{
	public class Weapon : MonoBehaviour
	{
		[SerializeField] private InputActionReference shootAction;
		[SerializeField] private Transform shootPoint;

		[CanBeNull] private IEntity player;

		private bool canShoot = true;

		public void SetPlayer(IEntity _player) => player = _player;

		private void Update()
		{
			if(player != null && canShoot && shootAction.action.IsDown())
			{
				bool didHit = Physics.Raycast(shootPoint.position, shootPoint.forward, out RaycastHit hit, player.Stats.Range);

				if(didHit && hit.collider.TryGetComponent(out EnemeyEntity entity))
				{
					entity.Stats.TakeDamage(player.Stats.Damage);
				}
			}
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