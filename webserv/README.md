# <div align="center">Webserv</div>
<div align="center">This is when you finally understand why a URL starts with HTTP.</div>

## 📝 Description
Webserv is a lightweight HTTP server written in C++98. Inspired by the design of NGINX and based on the HTTP 1.1 standard, this project demonstrates how an HTTP server handles real-world web traffic, parses requests, serves files, manages routing, and interacts with clients in a fully non-blocking, efficient manner.

### This server supports:
- Concurrent client handling using epoll()
- Parsing and responding to HTTP methods: GET, POST, and DELETE
- Chunked transfer decoding
- File uploads and directory listings
- Configurable routing and error handling
- Basic CGI integration

## ⚙️ How to Use
```bash
make
./webserv [path/to/config/file]
```
If no configuration file is provided, a default one will be used.

## 🧪 Testing
To test the functionality of the server:

### 1. Basic File Serving (GET)

Use a browser or curl:

```bash
curl http://localhost:5050/index.html
```

### 2. File Upload (POST)

Test with curl:

```bash
curl -F 'file=@path/to/upload.txt' http://localhost:5050/upload
```

### 3. File Deletion (DELETE)

Be careful with this one:

```bash
curl -X DELETE http://localhost:5050/filename
```

### 4. Directory Listing

Visit a configured directory path in the browser (e.g., `http://localhost:5050/list/`) and ensure the server generates a proper listing.

### 5. Redirection

Configure a route to redirect, then visit it to confirm the behavior.

### 6. Chunked Requests

Simulate using a script or tool like Postman with chunked encoding to verify parsing.

### 7. Compare with NGINX

For validation, replicate the same configuration and behavior in NGINX to ensure consistency in response codes and headers.

## 🙋‍♂️ My Contribution
For this project, I was responsible for the following key components:

### ✅ Request Parsing

- Implemented full support for parsing incoming HTTP requests (`GET`, `POST`, `DELETE`).
- Parsed headers, request body, and managed transfer encoding *(including chunked requests)*.
- Ensured correct behavior for malformed or incomplete requests.

### ✅ Routing System

- Developed the routing mechanism that maps requested URLs to file paths based on the configuration file.
- Integrated support for:
  - Default file serving when a directory is requested.
  - Auto-index *(directory listing)* if no default file is found.
  - HTTP redirections where configured.

### ✅ Method-Specific Handling

- **GET:** Served static files and directories with correct MIME types and error handling.
- **POST:** Handled file uploads with size limitations from the configuration.
- **DELETE:** Implemented secure file/directory deletion under specific permission scopes.

## 💡 Notes

- The server uses only one epoll() call for managing all client I/O.
- It is fully non-blocking and doesn’t rely on fork() outside of CGI handling.
- Compatible with all modern browsers.
- Default error pages are generated when custom ones are not set.
