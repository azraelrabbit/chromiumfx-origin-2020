// Copyright (c) 2014-2017 Wolfgang Borgsmüller
// All rights reserved.
// 
// This software may be modified and distributed under the terms
// of the BSD license. See the License.txt file for details.

// Generated file. Do not edit.


// cef_resource_skip_callback

// cont
static void cfx_resource_skip_callback_cont(cef_resource_skip_callback_t* self, int64 bytes_skipped) {
    self->cont(self, bytes_skipped);
}


