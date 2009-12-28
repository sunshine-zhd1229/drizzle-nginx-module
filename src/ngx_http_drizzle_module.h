#ifndef NGX_HTTP_DRIZZLE_MODULE_H
#define NGX_HTTP_DRIZZLE_MODULE_H

#include <ngx_config.h>
#include <nginx.h>
#include <ngx_http.h>

#include <libdrizzle/drizzle_client.h>

extern ngx_module_t ngx_http_drizzle_module;

typedef struct {
    ngx_http_upstream_conf_t             upstream;

    /* drizzle database name */
    ngx_http_complex_value_t            *dbname;

    /* SQL query to be executed */
    ngx_http_complex_value_t            *query;

    ngx_msec_t                          recv_cols_timeout;
    ngx_msec_t                          recv_rows_timeout;

} ngx_http_drizzle_loc_conf_t;


/* states for the drizzle client state machine */
typedef enum {
    state_db_connect,
    state_db_send_query,
    state_db_recv_cols,
    state_db_recv_rows

} ngx_http_drizzle_state_t;

#endif /* NGX_HTTP_DRIZZLE_MODULE_H */

