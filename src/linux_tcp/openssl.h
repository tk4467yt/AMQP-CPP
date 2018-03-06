/**
 *  OpenSSL.h
 * 
 *  Header file in which we list all openssl functions in our own namespace 
 *  that we call instead of the actual openssl functions. This allows us to 
 *  intercept the calls and forward them to a dynamically loaded namespace
 *  
 *  @author Emiel Bruijntjes <emiel.bruijntjes@copernica.com>
 *  @copyright 2018 Copernica BV
 */

/**
 *  Include guard
 */
#pragma once

/**
 *  Dependencies
 */
#include <openssl/ssl.h>

/**
 *  Begin of namespace
 */
namespace Copernica { namespace OpenSSL {
    
/**
 *	List of all methods that we need
 */
SSL_CTX *SSL_CTX_new(const SSL_METHOD *method);
SSL     *SSL_new(SSL_CTX *ctx);
int      SSL_do_handshake(SSL *ssl);
int      SSL_read(SSL *ssl, void *buf, int num);
int      SSL_write(SSL *ssl, const void *buf, int num);
int      SSL_shutdown(SSL *ssl);
int      SSL_set_fd(SSL *ssl, int fd);
int      SSL_get_error(const SSL *ssl, int ret);
int      SSL_up_ref(SSL *ssl);
void     SSL_set_connect_state(SSL *ssl);
void     SSL_free(SSL *ssl);

/**
 *  End of namespace
 */
}}
