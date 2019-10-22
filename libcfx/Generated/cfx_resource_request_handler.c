// Copyright (c) 2014-2017 Wolfgang Borgsmüller
// All rights reserved.
// 
// This software may be modified and distributed under the terms
// of the BSD license. See the License.txt file for details.

// Generated file. Do not edit.


// cef_resource_request_handler

typedef struct _cfx_resource_request_handler_t {
    cef_resource_request_handler_t cef_resource_request_handler;
    unsigned int ref_count;
    gc_handle_t gc_handle;
    int wrapper_kind;
    // managed callbacks
    void (CEF_CALLBACK *get_cookie_access_filter)(gc_handle_t self, cef_cookie_access_filter_t** __retval, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release);
    void (CEF_CALLBACK *on_before_resource_load)(gc_handle_t self, cef_return_value_t* __retval, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release, cef_request_callback_t* callback, int *callback_release);
    void (CEF_CALLBACK *get_resource_handler)(gc_handle_t self, cef_resource_handler_t** __retval, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release);
    void (CEF_CALLBACK *on_resource_redirect)(gc_handle_t self, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release, cef_response_t* response, int *response_release, char16 **new_url_str, int *new_url_length);
    void (CEF_CALLBACK *on_resource_response)(gc_handle_t self, int* __retval, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release, cef_response_t* response, int *response_release);
    void (CEF_CALLBACK *get_resource_response_filter)(gc_handle_t self, cef_response_filter_t** __retval, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release, cef_response_t* response, int *response_release);
    void (CEF_CALLBACK *on_resource_load_complete)(gc_handle_t self, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release, cef_response_t* response, int *response_release, cef_urlrequest_status_t status, int64 received_content_length);
    void (CEF_CALLBACK *on_protocol_execution)(gc_handle_t self, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release, int* allow_os_execution);
} cfx_resource_request_handler_t;

void CEF_CALLBACK _cfx_resource_request_handler_add_ref(struct _cef_base_ref_counted_t* base) {
    InterlockedIncrement(&((cfx_resource_request_handler_t*)base)->ref_count);
}
int CEF_CALLBACK _cfx_resource_request_handler_release(struct _cef_base_ref_counted_t* base) {
    int count = InterlockedDecrement(&((cfx_resource_request_handler_t*)base)->ref_count);
    if(count == 0) {
        if(((cfx_resource_request_handler_t*)base)->wrapper_kind == 0) {
            cfx_gc_handle_switch(&((cfx_resource_request_handler_t*)base)->gc_handle, GC_HANDLE_FREE);
        } else {
            cfx_gc_handle_switch(&((cfx_resource_request_handler_t*)base)->gc_handle, GC_HANDLE_FREE | GC_HANDLE_REMOTE);
        }
        free(base);
        return 1;
    }
    return 0;
}
int CEF_CALLBACK _cfx_resource_request_handler_has_one_ref(struct _cef_base_ref_counted_t* base) {
    return ((cfx_resource_request_handler_t*)base)->ref_count == 1 ? 1 : 0;
}

static cfx_resource_request_handler_t* cfx_resource_request_handler_ctor(gc_handle_t gc_handle, int wrapper_kind) {
    cfx_resource_request_handler_t* ptr = (cfx_resource_request_handler_t*)calloc(1, sizeof(cfx_resource_request_handler_t));
    if(!ptr) return 0;
    ptr->cef_resource_request_handler.base.size = sizeof(cef_resource_request_handler_t);
    ptr->cef_resource_request_handler.base.add_ref = _cfx_resource_request_handler_add_ref;
    ptr->cef_resource_request_handler.base.release = _cfx_resource_request_handler_release;
    ptr->cef_resource_request_handler.base.has_one_ref = _cfx_resource_request_handler_has_one_ref;
    ptr->ref_count = 1;
    ptr->gc_handle = gc_handle;
    ptr->wrapper_kind = wrapper_kind;
    return ptr;
}

// get_cookie_access_filter

cef_cookie_access_filter_t* CEF_CALLBACK cfx_resource_request_handler_get_cookie_access_filter(cef_resource_request_handler_t* self, cef_browser_t* browser, cef_frame_t* frame, cef_request_t* request) {
    cef_cookie_access_filter_t* __retval;
    int browser_release;
    int frame_release;
    int request_release;
    ((cfx_resource_request_handler_t*)self)->get_cookie_access_filter(((cfx_resource_request_handler_t*)self)->gc_handle, &__retval, browser, &browser_release, frame, &frame_release, request, &request_release);
    if(browser_release && browser) browser->base.release((cef_base_ref_counted_t*)browser);
    if(frame_release && frame) frame->base.release((cef_base_ref_counted_t*)frame);
    if(request_release && request) request->base.release((cef_base_ref_counted_t*)request);
    if(__retval) {
        ((cef_base_ref_counted_t*)__retval)->add_ref((cef_base_ref_counted_t*)__retval);
    }
    return __retval;
}

// on_before_resource_load

cef_return_value_t CEF_CALLBACK cfx_resource_request_handler_on_before_resource_load(cef_resource_request_handler_t* self, cef_browser_t* browser, cef_frame_t* frame, cef_request_t* request, cef_request_callback_t* callback) {
    cef_return_value_t __retval;
    int browser_release;
    int frame_release;
    int request_release;
    int callback_release;
    ((cfx_resource_request_handler_t*)self)->on_before_resource_load(((cfx_resource_request_handler_t*)self)->gc_handle, &__retval, browser, &browser_release, frame, &frame_release, request, &request_release, callback, &callback_release);
    if(browser_release && browser) browser->base.release((cef_base_ref_counted_t*)browser);
    if(frame_release && frame) frame->base.release((cef_base_ref_counted_t*)frame);
    if(request_release && request) request->base.release((cef_base_ref_counted_t*)request);
    if(callback_release && callback) callback->base.release((cef_base_ref_counted_t*)callback);
    return __retval;
}

// get_resource_handler

cef_resource_handler_t* CEF_CALLBACK cfx_resource_request_handler_get_resource_handler(cef_resource_request_handler_t* self, cef_browser_t* browser, cef_frame_t* frame, cef_request_t* request) {
    cef_resource_handler_t* __retval;
    int browser_release;
    int frame_release;
    int request_release;
    ((cfx_resource_request_handler_t*)self)->get_resource_handler(((cfx_resource_request_handler_t*)self)->gc_handle, &__retval, browser, &browser_release, frame, &frame_release, request, &request_release);
    if(browser_release && browser) browser->base.release((cef_base_ref_counted_t*)browser);
    if(frame_release && frame) frame->base.release((cef_base_ref_counted_t*)frame);
    if(request_release && request) request->base.release((cef_base_ref_counted_t*)request);
    if(__retval) {
        ((cef_base_ref_counted_t*)__retval)->add_ref((cef_base_ref_counted_t*)__retval);
    }
    return __retval;
}

// on_resource_redirect

void CEF_CALLBACK cfx_resource_request_handler_on_resource_redirect(cef_resource_request_handler_t* self, cef_browser_t* browser, cef_frame_t* frame, cef_request_t* request, cef_response_t* response, cef_string_t* new_url) {
    int browser_release;
    int frame_release;
    int request_release;
    int response_release;
    char16* new_url_tmp_str = new_url->str; int new_url_tmp_length = (int)new_url->length;
    ((cfx_resource_request_handler_t*)self)->on_resource_redirect(((cfx_resource_request_handler_t*)self)->gc_handle, browser, &browser_release, frame, &frame_release, request, &request_release, response, &response_release, &(new_url_tmp_str), &(new_url_tmp_length));
    if(browser_release && browser) browser->base.release((cef_base_ref_counted_t*)browser);
    if(frame_release && frame) frame->base.release((cef_base_ref_counted_t*)frame);
    if(request_release && request) request->base.release((cef_base_ref_counted_t*)request);
    if(response_release && response) response->base.release((cef_base_ref_counted_t*)response);
    if(new_url_tmp_str != new_url->str) {
        if(new_url->dtor) new_url->dtor(new_url->str);
        cef_string_set(new_url_tmp_str, new_url_tmp_length, new_url, 1);
        cfx_gc_handle_switch(&(gc_handle_t)new_url_tmp_str, GC_HANDLE_FREE);
    }
}

// on_resource_response

int CEF_CALLBACK cfx_resource_request_handler_on_resource_response(cef_resource_request_handler_t* self, cef_browser_t* browser, cef_frame_t* frame, cef_request_t* request, cef_response_t* response) {
    int __retval;
    int browser_release;
    int frame_release;
    int request_release;
    int response_release;
    ((cfx_resource_request_handler_t*)self)->on_resource_response(((cfx_resource_request_handler_t*)self)->gc_handle, &__retval, browser, &browser_release, frame, &frame_release, request, &request_release, response, &response_release);
    if(browser_release && browser) browser->base.release((cef_base_ref_counted_t*)browser);
    if(frame_release && frame) frame->base.release((cef_base_ref_counted_t*)frame);
    if(request_release && request) request->base.release((cef_base_ref_counted_t*)request);
    if(response_release && response) response->base.release((cef_base_ref_counted_t*)response);
    return __retval;
}

// get_resource_response_filter

cef_response_filter_t* CEF_CALLBACK cfx_resource_request_handler_get_resource_response_filter(cef_resource_request_handler_t* self, cef_browser_t* browser, cef_frame_t* frame, cef_request_t* request, cef_response_t* response) {
    cef_response_filter_t* __retval;
    int browser_release;
    int frame_release;
    int request_release;
    int response_release;
    ((cfx_resource_request_handler_t*)self)->get_resource_response_filter(((cfx_resource_request_handler_t*)self)->gc_handle, &__retval, browser, &browser_release, frame, &frame_release, request, &request_release, response, &response_release);
    if(browser_release && browser) browser->base.release((cef_base_ref_counted_t*)browser);
    if(frame_release && frame) frame->base.release((cef_base_ref_counted_t*)frame);
    if(request_release && request) request->base.release((cef_base_ref_counted_t*)request);
    if(response_release && response) response->base.release((cef_base_ref_counted_t*)response);
    if(__retval) {
        ((cef_base_ref_counted_t*)__retval)->add_ref((cef_base_ref_counted_t*)__retval);
    }
    return __retval;
}

// on_resource_load_complete

void CEF_CALLBACK cfx_resource_request_handler_on_resource_load_complete(cef_resource_request_handler_t* self, cef_browser_t* browser, cef_frame_t* frame, cef_request_t* request, cef_response_t* response, cef_urlrequest_status_t status, int64 received_content_length) {
    int browser_release;
    int frame_release;
    int request_release;
    int response_release;
    ((cfx_resource_request_handler_t*)self)->on_resource_load_complete(((cfx_resource_request_handler_t*)self)->gc_handle, browser, &browser_release, frame, &frame_release, request, &request_release, response, &response_release, status, received_content_length);
    if(browser_release && browser) browser->base.release((cef_base_ref_counted_t*)browser);
    if(frame_release && frame) frame->base.release((cef_base_ref_counted_t*)frame);
    if(request_release && request) request->base.release((cef_base_ref_counted_t*)request);
    if(response_release && response) response->base.release((cef_base_ref_counted_t*)response);
}

// on_protocol_execution

void CEF_CALLBACK cfx_resource_request_handler_on_protocol_execution(cef_resource_request_handler_t* self, cef_browser_t* browser, cef_frame_t* frame, cef_request_t* request, int* allow_os_execution) {
    int browser_release;
    int frame_release;
    int request_release;
    ((cfx_resource_request_handler_t*)self)->on_protocol_execution(((cfx_resource_request_handler_t*)self)->gc_handle, browser, &browser_release, frame, &frame_release, request, &request_release, allow_os_execution);
    if(browser_release && browser) browser->base.release((cef_base_ref_counted_t*)browser);
    if(frame_release && frame) frame->base.release((cef_base_ref_counted_t*)frame);
    if(request_release && request) request->base.release((cef_base_ref_counted_t*)request);
}

static void cfx_resource_request_handler_set_callback(cef_resource_request_handler_t* self, int index, void* callback) {
    switch(index) {
    case 0:
        ((cfx_resource_request_handler_t*)self)->get_cookie_access_filter = (void (CEF_CALLBACK *)(gc_handle_t self, cef_cookie_access_filter_t** __retval, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release))callback;
        self->get_cookie_access_filter = callback ? cfx_resource_request_handler_get_cookie_access_filter : 0;
        break;
    case 1:
        ((cfx_resource_request_handler_t*)self)->on_before_resource_load = (void (CEF_CALLBACK *)(gc_handle_t self, cef_return_value_t* __retval, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release, cef_request_callback_t* callback, int *callback_release))callback;
        self->on_before_resource_load = callback ? cfx_resource_request_handler_on_before_resource_load : 0;
        break;
    case 2:
        ((cfx_resource_request_handler_t*)self)->get_resource_handler = (void (CEF_CALLBACK *)(gc_handle_t self, cef_resource_handler_t** __retval, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release))callback;
        self->get_resource_handler = callback ? cfx_resource_request_handler_get_resource_handler : 0;
        break;
    case 3:
        ((cfx_resource_request_handler_t*)self)->on_resource_redirect = (void (CEF_CALLBACK *)(gc_handle_t self, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release, cef_response_t* response, int *response_release, char16 **new_url_str, int *new_url_length))callback;
        self->on_resource_redirect = callback ? cfx_resource_request_handler_on_resource_redirect : 0;
        break;
    case 4:
        ((cfx_resource_request_handler_t*)self)->on_resource_response = (void (CEF_CALLBACK *)(gc_handle_t self, int* __retval, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release, cef_response_t* response, int *response_release))callback;
        self->on_resource_response = callback ? cfx_resource_request_handler_on_resource_response : 0;
        break;
    case 5:
        ((cfx_resource_request_handler_t*)self)->get_resource_response_filter = (void (CEF_CALLBACK *)(gc_handle_t self, cef_response_filter_t** __retval, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release, cef_response_t* response, int *response_release))callback;
        self->get_resource_response_filter = callback ? cfx_resource_request_handler_get_resource_response_filter : 0;
        break;
    case 6:
        ((cfx_resource_request_handler_t*)self)->on_resource_load_complete = (void (CEF_CALLBACK *)(gc_handle_t self, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release, cef_response_t* response, int *response_release, cef_urlrequest_status_t status, int64 received_content_length))callback;
        self->on_resource_load_complete = callback ? cfx_resource_request_handler_on_resource_load_complete : 0;
        break;
    case 7:
        ((cfx_resource_request_handler_t*)self)->on_protocol_execution = (void (CEF_CALLBACK *)(gc_handle_t self, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release, int* allow_os_execution))callback;
        self->on_protocol_execution = callback ? cfx_resource_request_handler_on_protocol_execution : 0;
        break;
    }
}

