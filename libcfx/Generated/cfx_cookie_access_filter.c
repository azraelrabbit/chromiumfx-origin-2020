// Copyright (c) 2014-2017 Wolfgang Borgsmüller
// All rights reserved.
// 
// This software may be modified and distributed under the terms
// of the BSD license. See the License.txt file for details.

// Generated file. Do not edit.


// cef_cookie_access_filter

typedef struct _cfx_cookie_access_filter_t {
    cef_cookie_access_filter_t cef_cookie_access_filter;
    unsigned int ref_count;
    gc_handle_t gc_handle;
    int wrapper_kind;
    // managed callbacks
    void (CEF_CALLBACK *can_send_cookie)(gc_handle_t self, int* __retval, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release, const cef_cookie_t* cookie);
    void (CEF_CALLBACK *can_save_cookie)(gc_handle_t self, int* __retval, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release, cef_response_t* response, int *response_release, const cef_cookie_t* cookie);
} cfx_cookie_access_filter_t;

void CEF_CALLBACK _cfx_cookie_access_filter_add_ref(struct _cef_base_ref_counted_t* base) {
    InterlockedIncrement(&((cfx_cookie_access_filter_t*)base)->ref_count);
}
int CEF_CALLBACK _cfx_cookie_access_filter_release(struct _cef_base_ref_counted_t* base) {
    int count = InterlockedDecrement(&((cfx_cookie_access_filter_t*)base)->ref_count);
    if(count == 0) {
        if(((cfx_cookie_access_filter_t*)base)->wrapper_kind == 0) {
            cfx_gc_handle_switch(&((cfx_cookie_access_filter_t*)base)->gc_handle, GC_HANDLE_FREE);
        } else {
            cfx_gc_handle_switch(&((cfx_cookie_access_filter_t*)base)->gc_handle, GC_HANDLE_FREE | GC_HANDLE_REMOTE);
        }
        free(base);
        return 1;
    }
    return 0;
}
int CEF_CALLBACK _cfx_cookie_access_filter_has_one_ref(struct _cef_base_ref_counted_t* base) {
    return ((cfx_cookie_access_filter_t*)base)->ref_count == 1 ? 1 : 0;
}

static cfx_cookie_access_filter_t* cfx_cookie_access_filter_ctor(gc_handle_t gc_handle, int wrapper_kind) {
    cfx_cookie_access_filter_t* ptr = (cfx_cookie_access_filter_t*)calloc(1, sizeof(cfx_cookie_access_filter_t));
    if(!ptr) return 0;
    ptr->cef_cookie_access_filter.base.size = sizeof(cef_cookie_access_filter_t);
    ptr->cef_cookie_access_filter.base.add_ref = _cfx_cookie_access_filter_add_ref;
    ptr->cef_cookie_access_filter.base.release = _cfx_cookie_access_filter_release;
    ptr->cef_cookie_access_filter.base.has_one_ref = _cfx_cookie_access_filter_has_one_ref;
    ptr->ref_count = 1;
    ptr->gc_handle = gc_handle;
    ptr->wrapper_kind = wrapper_kind;
    return ptr;
}

// can_send_cookie

int CEF_CALLBACK cfx_cookie_access_filter_can_send_cookie(cef_cookie_access_filter_t* self, cef_browser_t* browser, cef_frame_t* frame, cef_request_t* request, const cef_cookie_t* cookie) {
    int __retval;
    int browser_release;
    int frame_release;
    int request_release;
    ((cfx_cookie_access_filter_t*)self)->can_send_cookie(((cfx_cookie_access_filter_t*)self)->gc_handle, &__retval, browser, &browser_release, frame, &frame_release, request, &request_release, cookie);
    if(browser_release && browser) browser->base.release((cef_base_ref_counted_t*)browser);
    if(frame_release && frame) frame->base.release((cef_base_ref_counted_t*)frame);
    if(request_release && request) request->base.release((cef_base_ref_counted_t*)request);
    return __retval;
}

// can_save_cookie

int CEF_CALLBACK cfx_cookie_access_filter_can_save_cookie(cef_cookie_access_filter_t* self, cef_browser_t* browser, cef_frame_t* frame, cef_request_t* request, cef_response_t* response, const cef_cookie_t* cookie) {
    int __retval;
    int browser_release;
    int frame_release;
    int request_release;
    int response_release;
    ((cfx_cookie_access_filter_t*)self)->can_save_cookie(((cfx_cookie_access_filter_t*)self)->gc_handle, &__retval, browser, &browser_release, frame, &frame_release, request, &request_release, response, &response_release, cookie);
    if(browser_release && browser) browser->base.release((cef_base_ref_counted_t*)browser);
    if(frame_release && frame) frame->base.release((cef_base_ref_counted_t*)frame);
    if(request_release && request) request->base.release((cef_base_ref_counted_t*)request);
    if(response_release && response) response->base.release((cef_base_ref_counted_t*)response);
    return __retval;
}

static void cfx_cookie_access_filter_set_callback(cef_cookie_access_filter_t* self, int index, void* callback) {
    switch(index) {
    case 0:
        ((cfx_cookie_access_filter_t*)self)->can_send_cookie = (void (CEF_CALLBACK *)(gc_handle_t self, int* __retval, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release, const cef_cookie_t* cookie))callback;
        self->can_send_cookie = callback ? cfx_cookie_access_filter_can_send_cookie : 0;
        break;
    case 1:
        ((cfx_cookie_access_filter_t*)self)->can_save_cookie = (void (CEF_CALLBACK *)(gc_handle_t self, int* __retval, cef_browser_t* browser, int *browser_release, cef_frame_t* frame, int *frame_release, cef_request_t* request, int *request_release, cef_response_t* response, int *response_release, const cef_cookie_t* cookie))callback;
        self->can_save_cookie = callback ? cfx_cookie_access_filter_can_save_cookie : 0;
        break;
    }
}

