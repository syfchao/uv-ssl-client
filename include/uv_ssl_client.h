#ifndef UV_SSL_CLIENT_H_
#define UV_SSL_CLIENT_H_

#include <cstdint>
#include <memory>
#include <stdexcept>

#include <uv.h>

namespace uv_ssl {

struct error : public std::runtime_error {
    explicit error(const char* msg);
    error(const char* func, const char *msg);
};

void shutdown();

struct client {
    client(const char* hostname, uint16_t port);

    explicit client(const char* hostname)
        : client(hostname, 443)
    {}

    void connect(uv_loop_t* loop);

    void connect() {
        connect(uv_default_loop());
    }

private:
    struct impl;
    std::unique_ptr<impl> impl_;
};

}  // namespace uv_ssl

#endif  // UV_SSL_CLIENT_H_
