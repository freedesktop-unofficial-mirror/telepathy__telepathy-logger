/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2009 Collabora Ltd.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Authors: Cosimo Alfarano <cosimo.alfarano@collabora.co.uk>
 */

#include <glib.h>

#include <telepathy-glib/dbus.h>
#include <telepathy-logger-dbus.h>

#include "dbus-service.h"

static GMainLoop *loop = NULL;

void telepathy_logger_dbus_init(void)
{
	TplDBusService *dbus_srv;
	DBusGConnection *bus;
	TpDBusDaemon *tp_bus;
	GError *error = NULL;

	bus = tp_get_bus();
	tp_bus = tp_dbus_daemon_new(bus);
	
	if ( tp_dbus_daemon_request_name (tp_bus, TPL_DBUS_SRV_WELL_KNOWN_BUS_NAME,
			TRUE, &error) ) {
		g_print("%s DBus well known name registered\n",
				TPL_DBUS_SRV_WELL_KNOWN_BUS_NAME);
	} else {
		g_print("Well Known name request error: %s\n", error->message);
		g_clear_error(&error);
		g_error_free(error);
	}

	dbus_srv = tpl_dbus_service_new ();
	dbus_g_connection_register_g_object (bus,
			TPL_DBUS_SRV_OBJECT_PATH,
			G_OBJECT(dbus_srv));
}

int main(int argc, char *argv[])
{
	g_type_init ();

	telepathy_logger_dbus_init ();

	loop = g_main_loop_new (NULL, FALSE);
	g_main_loop_run (loop);

	return 0;
}