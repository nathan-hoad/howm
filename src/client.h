#ifndef CLIENT_H
#define CLIENT_H

#include <stdbool.h>
#include <stdint.h>
#include <xcb/xproto.h>
#include <xcb/xcb.h>

#include "types.h"

/**
 * @file client.h
 *
 * @author Harvey Hunt
 *
 * @date 2014
 *
 * @brief howm
 */

enum teleport_locations { TOP_LEFT, TOP_CENTER, TOP_RIGHT, CENTER, BOTTOM_LEFT, BOTTOM_CENTER, BOTTOM_RIGHT };

int get_non_tff_count(void);
Client *get_first_non_tff(void);
void change_client_gaps(Client *c, int size);
void kill_client(const int ws, bool arrange);
void move_up(Client *c);
Client *next_client(Client *c);
void update_focused_client(Client *c);
Client *prev_client(Client *c, int ws);
Client *create_client(xcb_window_t w);
void remove_client(Client *c, bool refocus);
Client *find_client_by_win(xcb_window_t w);
void client_to_ws(Client *c, const int ws, bool follow);
void draw_clients(void);
void change_client_geom(Client *c, uint16_t x, uint16_t y, uint16_t w, uint16_t h);
void set_fullscreen(Client *c, bool fscr);
void set_urgent(Client *c, bool urg);
void move_client(int cnt, bool up);
void move_current_down(void);
void move_current_up(void);

void teleport_client(const int direction);
void focus_next_client(void);
void focus_prev_client(void);
void current_to_ws(const int ws);
void toggle_float(void);
void resize_float_width(const int dw);
void resize_float_height(const int dh);
void move_float_y(const int dy);
void move_float_x(const int dx);
void toggle_fullscreen(void);
void make_master(void);
void focus_urgent(void);
void resize_master(const int ds);
void paste(void);
void toggle_bar(void);

#endif
