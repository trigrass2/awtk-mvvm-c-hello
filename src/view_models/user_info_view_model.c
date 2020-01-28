﻿
/*This file is generated by code generator*/

#include "tkc/mem.h"
#include "tkc/utils.h"
#include "mvvm/base/utils.h"
#include "user_info_view_model.h"

static ret_t user_info_view_model_set_prop(object_t* obj, const char* name, const value_t* v) {
  user_info_t* user_info = ((user_info_view_model_t*)(obj))->user_info;

  if (tk_str_eq("name", name)) {
    return RET_OK;
  } else if (tk_str_eq("nick_name", name)) {
    return RET_OK;
  } else if (tk_str_eq("password", name)) {
    return RET_OK;
  } else if (tk_str_eq("registered_time", name)) {
    return RET_OK;
  } else if (tk_str_eq("last_login_time", name)) {
    return RET_OK;
  }

  return RET_NOT_FOUND;
}

static ret_t user_info_view_model_get_prop(object_t* obj, const char* name, value_t* v) {
  user_info_t* user_info = ((user_info_view_model_t*)(obj))->user_info;

  if (tk_str_eq("name", name)) {
    value_set_str(v, user_info->name.str);
    return RET_OK;
  } else if (tk_str_eq("nick_name", name)) {
    value_set_str(v, user_info->nick_name.str);
    return RET_OK;
  } else if (tk_str_eq("password", name)) {
    value_set_str(v, user_info->password.str);
    return RET_OK;
  } else if (tk_str_eq("registered_time", name)) {
    value_set_uint64(v, user_info->registered_time);
    return RET_OK;
  } else if (tk_str_eq("last_login_time", name)) {
    value_set_uint64(v, user_info->last_login_time);
    return RET_OK;
  }

  return RET_NOT_FOUND;
}

static bool_t user_info_view_model_can_exec(object_t* obj, const char* name, const char* args) {
  return FALSE;
}

static ret_t user_info_view_model_exec(object_t* obj, const char* name, const char* args) {
  return RET_NOT_FOUND;
}

static ret_t user_info_view_model_on_destroy(object_t* obj) {
  user_info_view_model_t* vm = (user_info_view_model_t*)(obj);
  return_value_if_fail(vm != NULL, RET_BAD_PARAMS);

  user_info_destroy(vm->user_info);

  return view_model_deinit(VIEW_MODEL(obj));
}

static const object_vtable_t s_user_info_view_model_vtable = {
    .type = "user_info_view_model_t",
    .desc = "user_info_view_model_t",
    .size = sizeof(user_info_view_model_t),
    .exec = user_info_view_model_exec,
    .can_exec = user_info_view_model_can_exec,
    .get_prop = user_info_view_model_get_prop,
    .set_prop = user_info_view_model_set_prop,
    .on_destroy = user_info_view_model_on_destroy};

view_model_t* user_info_view_model_create_with(user_info_t* user_info) {
  object_t* obj = object_create(&s_user_info_view_model_vtable);
  view_model_t* vm = view_model_init(VIEW_MODEL(obj));
  user_info_view_model_t* user_info_view_model = (user_info_view_model_t*)(vm);

  return_value_if_fail(vm != NULL, NULL);

  user_info_view_model->user_info = user_info;

  return vm;
}

ret_t user_info_view_model_attach(view_model_t* vm, user_info_t* user_info) {
  user_info_view_model_t* user_info_view_model = (user_info_view_model_t*)(vm);
  return_value_if_fail(vm != NULL, RET_BAD_PARAMS);

  user_info_view_model->user_info = user_info;

  return RET_OK;
}

view_model_t* user_info_view_model_create(navigator_request_t* req) {
  user_info_t* user_info = user_info_create(req);
  return_value_if_fail(user_info != NULL, NULL);

  return user_info_view_model_create_with(user_info);
}