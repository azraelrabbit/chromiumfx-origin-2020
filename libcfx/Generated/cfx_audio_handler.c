// Copyright (c) 2014-2017 Wolfgang Borgsmüller
// All rights reserved.
// 
// This software may be modified and distributed under the terms
// of the BSD license. See the License.txt file for details.

// Generated file. Do not edit.


// cef_audio_handler

typedef struct _cfx_audio_handler_t {
    cef_audio_handler_t cef_audio_handler;
    unsigned int ref_count;
    gc_handle_t gc_handle;
    int wrapper_kind;
    // managed callbacks
    void (CEF_CALLBACK *on_audio_stream_started)(gc_handle_t self, cef_browser_t* browser, int *browser_release, int audio_stream_id, int channels, cef_channel_layout_t channel_layout, int sample_rate, int frames_per_buffer);
    void (CEF_CALLBACK *on_audio_stream_packet)(gc_handle_t self, cef_browser_t* browser, int *browser_release, int audio_stream_id, const float** data, int frames, int64 pts);
    void (CEF_CALLBACK *on_audio_stream_stopped)(gc_handle_t self, cef_browser_t* browser, int *browser_release, int audio_stream_id);
} cfx_audio_handler_t;

void CEF_CALLBACK _cfx_audio_handler_add_ref(struct _cef_base_ref_counted_t* base) {
    InterlockedIncrement(&((cfx_audio_handler_t*)base)->ref_count);
}
int CEF_CALLBACK _cfx_audio_handler_release(struct _cef_base_ref_counted_t* base) {
    int count = InterlockedDecrement(&((cfx_audio_handler_t*)base)->ref_count);
    if(count == 0) {
        if(((cfx_audio_handler_t*)base)->wrapper_kind == 0) {
            cfx_gc_handle_switch(&((cfx_audio_handler_t*)base)->gc_handle, GC_HANDLE_FREE);
        } else {
            cfx_gc_handle_switch(&((cfx_audio_handler_t*)base)->gc_handle, GC_HANDLE_FREE | GC_HANDLE_REMOTE);
        }
        free(base);
        return 1;
    }
    return 0;
}
int CEF_CALLBACK _cfx_audio_handler_has_one_ref(struct _cef_base_ref_counted_t* base) {
    return ((cfx_audio_handler_t*)base)->ref_count == 1 ? 1 : 0;
}

static cfx_audio_handler_t* cfx_audio_handler_ctor(gc_handle_t gc_handle, int wrapper_kind) {
    cfx_audio_handler_t* ptr = (cfx_audio_handler_t*)calloc(1, sizeof(cfx_audio_handler_t));
    if(!ptr) return 0;
    ptr->cef_audio_handler.base.size = sizeof(cef_audio_handler_t);
    ptr->cef_audio_handler.base.add_ref = _cfx_audio_handler_add_ref;
    ptr->cef_audio_handler.base.release = _cfx_audio_handler_release;
    ptr->cef_audio_handler.base.has_one_ref = _cfx_audio_handler_has_one_ref;
    ptr->ref_count = 1;
    ptr->gc_handle = gc_handle;
    ptr->wrapper_kind = wrapper_kind;
    return ptr;
}

// on_audio_stream_started

void CEF_CALLBACK cfx_audio_handler_on_audio_stream_started(cef_audio_handler_t* self, cef_browser_t* browser, int audio_stream_id, int channels, cef_channel_layout_t channel_layout, int sample_rate, int frames_per_buffer) {
    int browser_release;
    ((cfx_audio_handler_t*)self)->on_audio_stream_started(((cfx_audio_handler_t*)self)->gc_handle, browser, &browser_release, audio_stream_id, channels, channel_layout, sample_rate, frames_per_buffer);
    if(browser_release && browser) browser->base.release((cef_base_ref_counted_t*)browser);
}

// on_audio_stream_packet

void CEF_CALLBACK cfx_audio_handler_on_audio_stream_packet(cef_audio_handler_t* self, cef_browser_t* browser, int audio_stream_id, const float** data, int frames, int64 pts) {
    int browser_release;
    ((cfx_audio_handler_t*)self)->on_audio_stream_packet(((cfx_audio_handler_t*)self)->gc_handle, browser, &browser_release, audio_stream_id, data, frames, pts);
    if(browser_release && browser) browser->base.release((cef_base_ref_counted_t*)browser);
}

// on_audio_stream_stopped

void CEF_CALLBACK cfx_audio_handler_on_audio_stream_stopped(cef_audio_handler_t* self, cef_browser_t* browser, int audio_stream_id) {
    int browser_release;
    ((cfx_audio_handler_t*)self)->on_audio_stream_stopped(((cfx_audio_handler_t*)self)->gc_handle, browser, &browser_release, audio_stream_id);
    if(browser_release && browser) browser->base.release((cef_base_ref_counted_t*)browser);
}

static void cfx_audio_handler_set_callback(cef_audio_handler_t* self, int index, void* callback) {
    switch(index) {
    case 0:
        ((cfx_audio_handler_t*)self)->on_audio_stream_started = (void (CEF_CALLBACK *)(gc_handle_t self, cef_browser_t* browser, int *browser_release, int audio_stream_id, int channels, cef_channel_layout_t channel_layout, int sample_rate, int frames_per_buffer))callback;
        self->on_audio_stream_started = callback ? cfx_audio_handler_on_audio_stream_started : 0;
        break;
    case 1:
        ((cfx_audio_handler_t*)self)->on_audio_stream_packet = (void (CEF_CALLBACK *)(gc_handle_t self, cef_browser_t* browser, int *browser_release, int audio_stream_id, const float** data, int frames, int64 pts))callback;
        self->on_audio_stream_packet = callback ? cfx_audio_handler_on_audio_stream_packet : 0;
        break;
    case 2:
        ((cfx_audio_handler_t*)self)->on_audio_stream_stopped = (void (CEF_CALLBACK *)(gc_handle_t self, cef_browser_t* browser, int *browser_release, int audio_stream_id))callback;
        self->on_audio_stream_stopped = callback ? cfx_audio_handler_on_audio_stream_stopped : 0;
        break;
    }
}

