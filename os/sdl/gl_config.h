//
// os/x11/gl_config.h: X11/OpenGL framebuffer configuration.
//
// CEN64: Cycle-Accurate Nintendo 64 Emulator.
// Copyright (C) 2015, Tyler J. Stachecki.
//
// This file is subject to the terms and conditions defined in
// 'LICENSE', which is part of this source code package.
//

#ifndef CEN64_OS_SDL_GL_CONFIG
#define CEN64_OS_SDL_GL_CONFIG
#include "gl_common.h"
#include "gl_display.h"
#include "gl_hints.h"
#include "gl_screen.h"
#include <stddef.h>
#include <SDL.h>

#define CEN64_GL_CONFIG_BAD (NULL)
typedef struct  {
}cen64_gl_config;

//
// Creates a matching cen64_gl_config from a cen64_gl_hints struct.
//
// On error, CEN64_GL_CONFIG_BAD is returned. On success, something
// other than CEN64_GL_CONFIG_BAD is returned, and matching is set
// to indicate the number of matches present in the returned array.
//
cen64_gl_config *cen64_gl_config_create(cen64_gl_display display,
                                        cen64_gl_screen screen, const cen64_gl_hints *hints, int *matching);

// Releases resources allocated by cen64_gl_config_create.
static inline void cen64_gl_config_destroy(cen64_gl_config *config)
{
}

//
// Fetches an attribute from the cen64_gl_config object.
//
// Used by the cen64_gl_config_get_* accessors.
//
int cen64_gl_config_fetch_attribute(cen64_gl_display display,
                                    cen64_gl_config *config, int what);

// Wrappers for querying for features/types.
static inline enum cen64_gl_context_type cen64_gl_config_get_context_type(
    cen64_gl_display display, cen64_gl_config *config)
{
    return CEN64_GL_CONTEXT_TYPE_RGBA;
}

static inline enum cen64_gl_drawable_type cen64_gl_config_get_drawable_type(
    cen64_gl_display display, cen64_gl_config *config)
{
    return CEN64_GL_DRAWABLE_TYPE_WINDOW;
}

static inline enum cen64_gl_layer_type cen64_gl_config_get_layer_type(
    cen64_gl_display display, cen64_gl_config *config)
{
    return CEN64_GL_LAYER_TYPE_DEFAULT;
}

static inline int cen64_gl_config_is_double_buffered(
    cen64_gl_display display, cen64_gl_config *config)
{
     return cen64_gl_config_fetch_attribute(display, config, SDL_GL_DOUBLEBUFFER) == 1;
}

static inline int cen64_gl_config_is_renderable(
    cen64_gl_display display, cen64_gl_config *config)
{
    return true;
}

static inline int cen64_gl_config_is_stereoscopic(
    cen64_gl_display display, cen64_gl_config *config)
{
     return cen64_gl_config_fetch_attribute(display, config, SDL_GL_STEREO) == 1;
}

// Wrappers for querying for color depths.
static inline int cen64_gl_config_get_color_depth(
    cen64_gl_display display, cen64_gl_config *config)
{
    return cen64_gl_config_fetch_attribute(display, config, SDL_GL_BUFFER_SIZE);
}

static inline int cen64_gl_config_get_red_color_depth(
    cen64_gl_display display, cen64_gl_config *config)
{
    return cen64_gl_config_fetch_attribute(display, config, SDL_GL_RED_SIZE);
}

static inline int cen64_gl_config_get_green_color_depth(
    cen64_gl_display display, cen64_gl_config *config)
{
    return cen64_gl_config_fetch_attribute(display, config, SDL_GL_GREEN_SIZE);
}

static inline int cen64_gl_config_get_blue_color_depth(
    cen64_gl_display display, cen64_gl_config *config)
{
    return cen64_gl_config_fetch_attribute(display, config, SDL_GL_BLUE_SIZE);
}

static inline int cen64_gl_config_get_alpha_color_depth(
    cen64_gl_display display, cen64_gl_config *config)
{
    return cen64_gl_config_fetch_attribute(display, config, SDL_GL_ALPHA_SIZE);
}

// Wrappers for querying for buffer sizes, counts.
static inline int cen64_gl_config_get_depth_buffer_count(
    cen64_gl_display display, cen64_gl_config *config)
{
    return cen64_gl_config_fetch_attribute(display, config, SDL_GL_DEPTH_SIZE);
}

static inline int cen64_gl_config_get_num_auxiliary_buffers(
    cen64_gl_display display, cen64_gl_config *config)
{
    return 0;
    //cen64_gl_config_fetch_attribute(display, config, SDL_GL_AUX_BUFFERS);
}

static inline int cen64_gl_config_get_stencil_buffer_size(
    cen64_gl_display display, cen64_gl_config *config)
{
    return cen64_gl_config_fetch_attribute(display, config, SDL_GL_STENCIL_SIZE);
}

// Wrappers for querying for accumulation buffer bits.
static inline int cen64_gl_config_get_red_accum_buffer_bits(
    cen64_gl_display display, cen64_gl_config *config)
{
    return cen64_gl_config_fetch_attribute(display, config, SDL_GL_ACCUM_RED_SIZE);
}

static inline int cen64_gl_config_get_blue_accum_buffer_bits(
    cen64_gl_display display, cen64_gl_config *config)
{
    return cen64_gl_config_fetch_attribute(display, config, SDL_GL_ACCUM_BLUE_SIZE);
}

static inline int cen64_gl_config_get_green_accum_buffer_bits(
    cen64_gl_display display, cen64_gl_config *config)
{
    return cen64_gl_config_fetch_attribute(display, config, SDL_GL_ACCUM_GREEN_SIZE);
}

static inline int cen64_gl_config_get_alpha_accum_buffer_bits(
    cen64_gl_display display, cen64_gl_config *config)
{
    return cen64_gl_config_fetch_attribute(display, config, SDL_GL_ACCUM_ALPHA_SIZE);
}

#endif
