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

#ifndef __TPL_ENTRY_TEXT_H__
#define __TPL_ENTRY_TEXT_H__

#include <glib-object.h>

#include <telepathy-logger/entry.h>

G_BEGIN_DECLS
#define TPL_TYPE_ENTRY_TEXT                  (tpl_entry_text_get_type ())
#define TPL_ENTRY_TEXT(obj)                  (G_TYPE_CHECK_INSTANCE_CAST ((obj), TPL_TYPE_ENTRY_TEXT, TplEntryText))
#define TPL_ENTRY_TEXT_CLASS(klass)          (G_TYPE_CHECK_CLASS_CAST ((klass), TPL_TYPE_ENTRY_TEXT, TplEntryTextClass))
#define TPL_IS_ENTRY_TEXT(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TPL_TYPE_ENTRY_TEXT))
#define TPL_IS_ENTRY_TEXT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TPL_TYPE_ENTRY_TEXT))
#define TPL_ENTRY_TEXT_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), TPL_TYPE_ENTRY_TEXT, TplEntryTextClass))

typedef struct _TplEntryText TplEntryText;
typedef struct _TplEntryTextClass TplEntryTextClass;
typedef struct _TplEntryTextPriv TplEntryTextPriv;

GType tpl_entry_text_get_type (void);

const gchar *tpl_entry_text_get_message (TplEntryText *self);

G_END_DECLS
#endif // __TPL_ENTRY_TEXT_H__