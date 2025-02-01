DIR="./srcs/docker-compose.yml"

up:
	@docker compose -f $(DIR) up --build -d

down:
	@docker compose -f $(DIR) down

ps:
	@docker compose -f $(DIR) ps

fclean:
	@docker system prune -af