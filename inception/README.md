# <div align="center">Inception</div>

## Overview
Inception is a system administration project that involves setting up multiple Docker containers to host a WordPress website with a MariaDB database and NGINX server using TLS encryption. The project also includes additional bonus services to enhance functionality.

## Mandatory Requirements
The mandatory part of the project requires setting up the following:

- `NGINX Container`: Serves the WordPress website with TLSv1.2 or TLSv1.3 encryption.
- `WordPress + PHP-FPM Container`: Runs WordPress without NGINX.
- `MariaDB Container`: Stores the WordPress database.
- `Persistent Storage`:
  - A volume for the WordPress database.
  - A volume for WordPress website files.
- `Docker Network`: Establishes communication between the containers.

A detailed guide for setting up the mandatory part can be found in [this repo](https://github.com/belmqadem/inception).

## Bonus Features
For the bonus part, additional services are set up to extend the project:

- `Redis Cache`: Improves performance by caching WordPress content.
- `FTP Server`: Allows file transfers to the WordPress volume.
- `Static Website`: A simple static site (not in PHP) such as a personal portfolio or showcase site.
- `Adminer`: A web-based database management tool for MariaDB.
- `Additional Service`: A custom service chosen based on utility (to be justified during the defense).

Each of these services runs in its own Docker container with dedicated volumes if necessary.

## License
This project is for educational purposes and follows 42 School's guidelines.

---

For detailed setup instructions, refer to the guide in the repository.
