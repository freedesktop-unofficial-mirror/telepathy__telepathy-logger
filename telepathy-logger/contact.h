/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *Copyright (C) 2009-2010 Collabora Ltd.
 *
 *This library is free software; you can redistribute it and/or
 *modify it under the terms of the GNU Lesser General Public
 *License as published by the Free Software Foundation; either
 *version 2.1 of the License, or (at your option) any later version.
 *
 *This library is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *Lesser General Public License for more details.
 *
 *You should have received a copy of the GNU Lesser General Public
 *License along with this library; if not, write to the Free Software
 *Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *Authors: Cosimo Alfarano <cosimo.alfarano@collabora.co.uk>
 */

#ifndef __TPL_CONTACT_H__
#define __TPL_CONTACT_H__

#include <glib-object.h>
#include <telepathy-glib/contact.h>

G_BEGIN_DECLS
#define TPL_TYPE_CONTACT    (tpl_contact_get_type ())
#define TPL_CONTACT(obj)    (G_TYPE_CHECK_INSTANCE_CAST ((obj), TPL_TYPE_CONTACT, TplContact))
#define TPL_CONTACT_CLASS(klass)  (G_TYPE_CHECK_CLASS_CAST ((klass), TPL_TYPE_CONTACT, TplContactClass))
#define TPL_IS_CONTACT(obj)    (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TPL_TYPE_CONTACT))
#define TPL_IS_CONTACT_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), TPL_TYPE_CONTACT))
#define TPL_CONTACT_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), TPL_TYPE_CONTACT, TplContactClass))

/* TplContactType:
 *
 * @TPL_CONTACT_UNKNOWN: the current contact's type is unknown
 * @TPL_CONTACT_USER: the contact's type represents a user (buddy), but not
 * the the account's owner for which @TPL_CONTACT_SELF is used
 * @TPL_CONTACT_GROUP: a named chatroom (#TP_HANDLE_TYPE_ROOM)
 * @TPL_CONTACT_SELF: the contact's type represents the owner of the account
 * whose channel has been logged, as opposed to @TPL_CONTACT_USER which
 * represents any other user
 */
typedef enum
{
  TPL_CONTACT_UNKNOWN,
  /* contact is a user (buddy) */
  TPL_CONTACT_USER,
  /* contact is a chatroom, meaning that the related message has been sent to
   * a chatroom instead of to a 1-1 channel */
  TPL_CONTACT_GROUP,
  /* contact is both a USER and the account's owner (self-handle) */
  TPL_CONTACT_SELF
} TplContactType;

typedef struct _TplContactPriv TplContactPriv;
typedef struct
{
  GObject parent;

  /*Private */
  TplContactPriv *priv;
} TplContact;


GType tpl_contact_get_type (void);

TplContact *tpl_contact_from_tp_contact (TpContact *contact);

TpContact *tpl_contact_get_contact (TplContact *self);

const gchar *tpl_contact_get_alias (TplContact *self);
const gchar *tpl_contact_get_identifier (TplContact *self);
TplContactType tpl_contact_get_contact_type (TplContact *self);
const gchar *tpl_contact_get_avatar_token (TplContact *self);

G_END_DECLS
#endif // __TPL_CONTACT_H__
