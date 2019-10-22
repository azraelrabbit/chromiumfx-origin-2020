// Copyright (c) 2014-2017 Wolfgang Borgsmüller
// All rights reserved.
// 
// This software may be modified and distributed under the terms
// of the BSD license. See the License.txt file for details.

// Generated file. Do not edit.


// cef_request_context_handler

typedef struct _cfx_request_context_handler_t {
    cef_request_context_handler_t cef_request_context_handler;
    unsigned int ref_count;
    gc_handle_t gc_handle;
    int wrapper_kind;
    // managed callbacks
    void (CEF_CALLBACK *on_request_context_initialized)(gc_handle_t self, cef_request_context_t* request_context, int *request_context_release);
    void (CEF_CALLBACK *on_before_plugin_load)(gc_handle_t self, int* __retval, char16 *mime_type_str, int mime_type_length, char16 *plugin_url_str, int plugin_url_length, int is_main_frame, char16 *top_origin_url_str, int top_origin_url_length, cef_web_plugin_info_t* plugin_info, int *plugin_info_release, cef_plugin_policy_t* plugin_policy);
    void (CEF_CALLBACK *get_resource_request_handler)(gc_handle_t self, cef_resource_request_handler_t** __retval, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release, int is_navigation, int is_download, char16 *request_initiator_str, int request_initiator_length, int* disable_default_handling);
} cfx_request_context_handler_t;

void CEF_CALLBACK _cfx_request_context_handler_add_ref(struct _cef_base_ref_counted_t* base) {
    InterlockedIncrement(&((cfx_request_context_handler_t*)base)->ref_count);
}
int CEF_CALLBACK _cfx_request_context_handler_release(struct _cef_base_ref_counted_t* base) {
    int count = InterlockedDecrement(&((cfx_request_context_handler_t*)base)->ref_count);
    if(count == 0) {
        if(((cfx_request_context_handler_t*)base)->wrapper_kind == 0) {
            cfx_gc_handle_switch(&((cfx_request_context_handler_t*)base)->gc_handle, GC_HANDLE_FREE);
        } else {
            cfx_gc_handle_switch(&((cfx_request_context_handler_t*)base)->gc_handle, GC_HANDLE_FREE | GC_HANDLE_REMOTE);
        }
        free(base);
        return 1;
    }
    return 0;
}
int CEF_CALLBACK _cfx_request_context_handler_has_one_ref(struct _cef_base_ref_counted_t* base) {
    return ((cfx_request_context_handler_t*)base)->ref_count == 1 ? 1 : 0;
}

static cfx_request_context_handler_t* cfx_request_context_handler_ctor(gc_handle_t gc_handle, int wrapper_kind) {
    cfx_request_context_handler_t* ptr = (cfx_request_context_handler_t*)calloc(1, sizeof(cfx_request_context_handler_t));
    if(!ptr) return 0;
    ptr->cef_request_context_handler.base.size = sizeof(cef_request_context_handler_t);
    ptr->cef_request_context_handler.base.add_ref = _cfx_request_context_handler_add_ref;
    ptr->cef_request_context_handler.base.release = _cfx_request_context_handler_release;
    ptr->cef_request_context_handler.base.has_one_ref = _cfx_request_context_handler_has_one_ref;
    ptr->ref_count = 1;
    ptr->gc_handle = gc_handle;
    ptr->wrapper_kind = wrapper_kind;
    return ptr;
}

static gc_handle_t cfx_request_context_handler_get_gc_handle(cfx_request_context_handler_t* self) {
    return self->gc_handle;
}

// on_request_context_initialized

void CEF_CALLBACK cfx_request_context_handler_on_request_context_initialized(cef_request_context_handler_t* self, cef_request_context_t* request_context) {
    int request_context_release;
    ((cfx_request_context_handler_t*)self)->on_request_context_initialized(((cfx_request_context_handler_t*)self)->gc_handle, request_context, &request_context_release);
    if(request_context_release && request_context) request_context->base.release((cef_base_ref_counted_t*)request_context);
}

// on_before_plugin_load

int CEF_CALLBACK cfx_request_context_handler_on_before_plugin_load(cef_request_context_handler_t* self, const cef_string_t* mime_type, const cef_string_t* plugin_url, int is_main_frame, const cef_string_t* top_origin_url, cef_web_plugin_info_t* plugin_info, cef_plugin_policy_t* plugin_policy) {
    int __retval;
    int plugin_info_release;
    ((cfx_request_context_handler_t*)self)->on_before_plugin_load(((cfx_request_context_handler_t*)self)->gc_handle, &__retval, mime_type ? mime_type->str : 0, mime_type ? (int)mime_type->length : 0, plugin_url ? plugin_url->str : 0, plugin_url ? (int)plugin_url->length : 0, is_main_frame, top_origin_url ? top_origin_url->str : 0, top_origin_url ? (int)top_origin_url->length : 0, plugin_info, &plugin_info_release, plugin_policy);
    if(plugin_info_release && plugin_info) plugin_info->base.release((cef_base_ref_counted_t*)plugin_info);
    return __retval;
}

// get_resource_request_handler

cef_resource_request_handler_t* CEF_CALLBACK cfx_request_context_handler_get_resource_request_handler(cef_request_context_handler_t* self, cef_browser_t* browser, cef_frame_t* frame, cef_request_t* request, int is_navigation, int is_download, const cef_string_t* request_initiator, int* disable_default_handling) {
    cef_resource_request_handler_t* __retval;
    int browser_release;
    int frame_release;
    int request_release;
    ((cfx_request_context_handler_t*)self)->get_resource_request_handler(((cfx_request_context_handler_t*)self)->gc_handle, &__retval, browser, &browser_release, frame, &frame_release, request, &request_release, is_navigation, is_download, request_initiator ? request_initiator->str : 0, request_initiator ? (int)request_initiator->length : 0, disable_default_handling);
    if(browser_release && browser) browser->base.release((cef_base_ref_counted_t*)browser);
    if(frame_release && frame) frame->base.release((cef_base_ref_counted_t*)frame);
    if(request_release && request) request->base.release((cef_base_ref_counted_t*)request);
    if(__retval) {
        ((cef_base_ref_counted_t*)__retval)->add_ref((cef_base_ref_counted_t*)__retval);
    }
    return __retval;
}

static void cfx_request_context_handler_set_callback(cef_request_context_handler_t* self, int index, void* callback) {
    switch(index) {
    case 0:
        ((cfx_request_context_handler_t*)self)->on_request_context_initialized = (void (CEF_CALLBACK *)(gc_handle_t self, cef_request_context_t* request_context, int *request_context_release))callback;
        self->on_request_context_initialized = callback ? cfx_request_context_handler_on_request_context_initialized : 0;
        break;
    case 1:
        ((cfx_request_context_handler_t*)self)->on_before_plugin_load = (void (CEF_CALLBACK *)(gc_handle_t self, int* __retval, char16 *mime_type_str, int mime_type_length, char16 *plugin_url_str, int plugin_url_length, int is_main_frame, char16 *top_origin_url_str, int top_origin_url_length, cef_web_plugin_info_t* plugin_info, int *plugin_info_release, cef_plugin_policy_t* plugin_policy))callback;
        self->on_before_plugin_load = callback ? cfx_request_context_handler_on_before_plugin_load : 0;
        break;
    case 2:
        ((cfx_request_context_handler_t*)self)->get_resource_request_handler = (void (CEF_CALLBACK *)(gc_handle_t self, cef_resource_request_handler_t** __retval, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release, int is_navigation, int is_download, char16 *request_initiator_str, int request_initiator_length, int* disable_default_handling))callback;
        self->get_resource_request_handler = callback ? cfx_request_context_handler_get_resource_request_handler : 0;
        break;
    }
}

