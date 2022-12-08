using System;
using System.Collections;

using ThirdPersonShooter.Entities.Player;

using UnityEngine;
using UnityEngine.AI;

namespace ThirdPersonShooter.Entities.AI
{
	public class EnemeyEntity : MonoBehaviour, IEntity
	{
		private static readonly int deadHash = Animator.StringToHash("Dead");
		private static readonly int playerDeadHash = Animator.StringToHash("PlayerDead");

		public ref Stats Stats => ref stats;
		public Vector3 Position => transform.position;

		[SerializeField] private Stats stats;
		[SerializeField] private int value = 1;

		[Header("Components")] 
		[SerializeField] private Animator animator;
		[SerializeField] private AudioSource hurtSource;
		[SerializeField] private AudioSource deathSource;

		[Header("Debug")] 
		[SerializeField] private bool skipPathfinding;
		
		private PlayerEntity player;
		private NavMeshAgent agent;

		private bool isAttackCooling;
		private bool isPlayerDead;

		private new Collider collider;

		private void Start()
		{
			stats.Start();

			agent = gameObject.GetComponent<NavMeshAgent>();
			agent.speed = stats.Speed;

			collider = gameObject.GetComponent<CapsuleCollider>();

			player = GameManager.IsValid() ? GameManager.Instance.Player : FindObjectOfType<PlayerEntity>();
		}

		private void Update()
		{
			if(isPlayerDead || skipPathfinding)
			{
				return;
			}

			agent.SetDestination(player.Position);

			if(Vector3.Distance(player.Position, transform.position) < stats.Range)
			{
				if(!isAttackCooling)
				{
					player.Stats.TakeDamage(stats.Damage);
					StartCoroutine(AttackCooldown_CR());
				}
			}
		}

		private IEnumerator AttackCooldown_CR()
		{
			isAttackCooling = true;

			yield return new WaitForSeconds(stats.AttackRate);

			isAttackCooling = false;
		}
	}
}