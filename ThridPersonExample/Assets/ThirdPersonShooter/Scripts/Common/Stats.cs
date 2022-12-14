using System;

using UnityEngine;

namespace ThirdPersonShooter
{
	[Serializable]
	public struct Stats
	{
		public float Speed => speed * SpeedModifier;
		public float MaxHealth => maxHealth;
		public float Range => range;
		public float Damage => damage;
		public float AttackRate => attackRate;
		public int MaxAmmo => maxAmmo;

		public float Health { get; private set; }
		public float SpeedModifier { get; set; }

		public Action<float> onHealthChanged;
		public Action onDeath;

		[SerializeField, Min(1.0f)] private float maxHealth;
		[SerializeField, Range(.1f, 10f)] private float speed;

		[SerializeField] private float range;
		[SerializeField] private float damage;
		[SerializeField] private float attackRate;
		[SerializeField] private int maxAmmo;

		public void Start()
		{
			Health = maxHealth;
			SpeedModifier = 1.0f;
		}

		public void TakeDamage(float _damageAmount)
		{
			if(Health <= 0)
			{
				return;
			}

			Health -= _damageAmount;
			onHealthChanged?.Invoke(Health);
			
			if(Health <= 0)
			{
				onDeath?.Invoke();
			}
		}
	}
}