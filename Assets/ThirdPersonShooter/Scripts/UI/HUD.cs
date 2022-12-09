using ThirdPersonShooter.Entities.Player;

using TMPro;

using UnityEngine;
using UnityEngine.UI;

namespace ThirdPersonShooter.UI
{
	public class HUD : MenuBase
	{
		public override string ID => "HUD";

		private PlayerEntity player;

		[SerializeField] private Slider healthBar;
		[SerializeField] private TextMeshProUGUI scoreText;
		[SerializeField] private TextMeshProUGUI ammoText;

		public override void OnOpenMenu(UIManager _manager)
		{
			player = GameManager.IsValid() ? GameManager.Instance.Player : FindObjectOfType<PlayerEntity>();
			
			player.Stats.onHealthChanged += OnHealthChanged;
			player.Stats.onDeath += OnPlayerDied;
			player.onScroreUpdated += OnScoreUpdated;
			player.onAmmoUpdated += OnAmmoUpdated;

			healthBar.maxValue = player.Stats.MaxHealth;
			healthBar.value = player.Stats.Health;
			
		}

		public override void OnCloseMenu(UIManager _manager)
		{
			player.Stats.onHealthChanged -= OnHealthChanged;
			player.Stats.onDeath -= OnPlayerDied;
			player.onScroreUpdated -= OnScoreUpdated;
			player.onAmmoUpdated -= OnAmmoUpdated;
		}

		private void OnHealthChanged(float _health) => healthBar.value = _health;
		
		private void OnPlayerDied() => UIManager.ShowMenu("Game Over");

		private void OnScoreUpdated(int _score) => scoreText.text = $"Score: {_score}";

		private void OnAmmoUpdated(int _ammo) => ammoText.text = $"{_ammo}/{player.Stats.MaxAmmo}";
	}
}