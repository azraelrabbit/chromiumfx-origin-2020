// Copyright (c) 2014-2017 Wolfgang Borgsmüller
// All rights reserved.
// 
// This software may be modified and distributed under the terms
// of the BSD license. See the License.txt file for details.

// Generated file. Do not edit.


// cef_touch_event

static cef_touch_event_t* cfx_touch_event_ctor() {
    return (cef_touch_event_t*)calloc(1, sizeof(cef_touch_event_t));
}

static void cfx_touch_event_dtor(cef_touch_event_t* self) {
    free(self);
}

// cef_touch_event_t->id
static void cfx_touch_event_set_id(cef_touch_event_t *self, int id) {
    self->id = id;
}
static void cfx_touch_event_get_id(cef_touch_event_t *self, int* id) {
    *id = self->id;
}

// cef_touch_event_t->x
static void cfx_touch_event_set_x(cef_touch_event_t *self, float x) {
    self->x = x;
}
static void cfx_touch_event_get_x(cef_touch_event_t *self, float* x) {
    *x = self->x;
}

// cef_touch_event_t->y
static void cfx_touch_event_set_y(cef_touch_event_t *self, float y) {
    self->y = y;
}
static void cfx_touch_event_get_y(cef_touch_event_t *self, float* y) {
    *y = self->y;
}

// cef_touch_event_t->radius_x
static void cfx_touch_event_set_radius_x(cef_touch_event_t *self, float radius_x) {
    self->radius_x = radius_x;
}
static void cfx_touch_event_get_radius_x(cef_touch_event_t *self, float* radius_x) {
    *radius_x = self->radius_x;
}

// cef_touch_event_t->radius_y
static void cfx_touch_event_set_radius_y(cef_touch_event_t *self, float radius_y) {
    self->radius_y = radius_y;
}
static void cfx_touch_event_get_radius_y(cef_touch_event_t *self, float* radius_y) {
    *radius_y = self->radius_y;
}

// cef_touch_event_t->rotation_angle
static void cfx_touch_event_set_rotation_angle(cef_touch_event_t *self, float rotation_angle) {
    self->rotation_angle = rotation_angle;
}
static void cfx_touch_event_get_rotation_angle(cef_touch_event_t *self, float* rotation_angle) {
    *rotation_angle = self->rotation_angle;
}

// cef_touch_event_t->pressure
static void cfx_touch_event_set_pressure(cef_touch_event_t *self, float pressure) {
    self->pressure = pressure;
}
static void cfx_touch_event_get_pressure(cef_touch_event_t *self, float* pressure) {
    *pressure = self->pressure;
}

// cef_touch_event_t->type
static void cfx_touch_event_set_type(cef_touch_event_t *self, cef_touch_event_type_t type) {
    self->type = type;
}
static void cfx_touch_event_get_type(cef_touch_event_t *self, cef_touch_event_type_t* type) {
    *type = self->type;
}

// cef_touch_event_t->modifiers
static void cfx_touch_event_set_modifiers(cef_touch_event_t *self, uint32 modifiers) {
    self->modifiers = modifiers;
}
static void cfx_touch_event_get_modifiers(cef_touch_event_t *self, uint32* modifiers) {
    *modifiers = self->modifiers;
}

// cef_touch_event_t->pointer_type
static void cfx_touch_event_set_pointer_type(cef_touch_event_t *self, cef_pointer_type_t pointer_type) {
    self->pointer_type = pointer_type;
}
static void cfx_touch_event_get_pointer_type(cef_touch_event_t *self, cef_pointer_type_t* pointer_type) {
    *pointer_type = self->pointer_type;
}


