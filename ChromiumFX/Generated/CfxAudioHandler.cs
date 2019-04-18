// Copyright (c) 2014-2017 Wolfgang Borgsmüller
// All rights reserved.
// 
// This software may be modified and distributed under the terms
// of the BSD license. See the License.txt file for details.

// Generated file. Do not edit.


using System;

namespace Chromium {
    using Event;

    /// <summary>
    /// Implement this structure to handle audio events All functions will be called
    /// on the UI thread
    /// </summary>
    /// <remarks>
    /// See also the original CEF documentation in
    /// <see href="https://bitbucket.org/chromiumfx/chromiumfx/src/tip/cef/include/capi/cef_audio_handler_capi.h">cef/include/capi/cef_audio_handler_capi.h</see>.
    /// </remarks>
    public class CfxAudioHandler : CfxBaseClient {

        private static object eventLock = new object();

        internal static void SetNativeCallbacks() {
            on_audio_stream_started_native = on_audio_stream_started;
            on_audio_stream_packet_native = on_audio_stream_packet;
            on_audio_stream_stopped_native = on_audio_stream_stopped;

            on_audio_stream_started_native_ptr = System.Runtime.InteropServices.Marshal.GetFunctionPointerForDelegate(on_audio_stream_started_native);
            on_audio_stream_packet_native_ptr = System.Runtime.InteropServices.Marshal.GetFunctionPointerForDelegate(on_audio_stream_packet_native);
            on_audio_stream_stopped_native_ptr = System.Runtime.InteropServices.Marshal.GetFunctionPointerForDelegate(on_audio_stream_stopped_native);
        }

        // on_audio_stream_started
        [System.Runtime.InteropServices.UnmanagedFunctionPointer(System.Runtime.InteropServices.CallingConvention.StdCall, SetLastError = false)]
        private delegate void on_audio_stream_started_delegate(IntPtr gcHandlePtr, IntPtr browser, out int browser_release, int audio_stream_id, int channels, int channel_layout, int sample_rate, int frames_per_buffer);
        private static on_audio_stream_started_delegate on_audio_stream_started_native;
        private static IntPtr on_audio_stream_started_native_ptr;

        internal static void on_audio_stream_started(IntPtr gcHandlePtr, IntPtr browser, out int browser_release, int audio_stream_id, int channels, int channel_layout, int sample_rate, int frames_per_buffer) {
            var self = (CfxAudioHandler)System.Runtime.InteropServices.GCHandle.FromIntPtr(gcHandlePtr).Target;
            if(self == null || self.CallbacksDisabled) {
                browser_release = 1;
                return;
            }
            var e = new CfxOnAudioStreamStartedEventArgs();
            e.m_browser = browser;
            e.m_audio_stream_id = audio_stream_id;
            e.m_channels = channels;
            e.m_channel_layout = channel_layout;
            e.m_sample_rate = sample_rate;
            e.m_frames_per_buffer = frames_per_buffer;
            self.m_OnAudioStreamStarted?.Invoke(self, e);
            e.m_isInvalid = true;
            browser_release = e.m_browser_wrapped == null? 1 : 0;
        }

        // on_audio_stream_packet
        [System.Runtime.InteropServices.UnmanagedFunctionPointer(System.Runtime.InteropServices.CallingConvention.StdCall, SetLastError = false)]
        private delegate void on_audio_stream_packet_delegate(IntPtr gcHandlePtr, IntPtr browser, out int browser_release, int audio_stream_id, IntPtr data, int frames, long pts);
        private static on_audio_stream_packet_delegate on_audio_stream_packet_native;
        private static IntPtr on_audio_stream_packet_native_ptr;

        internal static void on_audio_stream_packet(IntPtr gcHandlePtr, IntPtr browser, out int browser_release, int audio_stream_id, IntPtr data, int frames, long pts) {
            var self = (CfxAudioHandler)System.Runtime.InteropServices.GCHandle.FromIntPtr(gcHandlePtr).Target;
            if(self == null || self.CallbacksDisabled) {
                browser_release = 1;
                return;
            }
            var e = new CfxOnAudioStreamPacketEventArgs();
            e.m_browser = browser;
            e.m_audio_stream_id = audio_stream_id;
            e.m_data = data;
            e.m_frames = frames;
            e.m_pts = pts;
            self.m_OnAudioStreamPacket?.Invoke(self, e);
            e.m_isInvalid = true;
            browser_release = e.m_browser_wrapped == null? 1 : 0;
        }

        // on_audio_stream_stopped
        [System.Runtime.InteropServices.UnmanagedFunctionPointer(System.Runtime.InteropServices.CallingConvention.StdCall, SetLastError = false)]
        private delegate void on_audio_stream_stopped_delegate(IntPtr gcHandlePtr, IntPtr browser, out int browser_release, int audio_stream_id);
        private static on_audio_stream_stopped_delegate on_audio_stream_stopped_native;
        private static IntPtr on_audio_stream_stopped_native_ptr;

        internal static void on_audio_stream_stopped(IntPtr gcHandlePtr, IntPtr browser, out int browser_release, int audio_stream_id) {
            var self = (CfxAudioHandler)System.Runtime.InteropServices.GCHandle.FromIntPtr(gcHandlePtr).Target;
            if(self == null || self.CallbacksDisabled) {
                browser_release = 1;
                return;
            }
            var e = new CfxOnAudioStreamStoppedEventArgs();
            e.m_browser = browser;
            e.m_audio_stream_id = audio_stream_id;
            self.m_OnAudioStreamStopped?.Invoke(self, e);
            e.m_isInvalid = true;
            browser_release = e.m_browser_wrapped == null? 1 : 0;
        }

        public CfxAudioHandler() : base(CfxApi.AudioHandler.cfx_audio_handler_ctor) {}

        /// <summary>
        /// Called when the stream identified by |AudioStreamId| has started.
        /// |AudioStreamId| will uniquely identify the stream across all future
        /// CfxAudioHandler callbacks. OnAudioSteamStopped will always be called
        /// after OnAudioStreamStarted; both functions may be called multiple times for
        /// the same stream. |Channels| is the number of channels, |ChannelLayout| is
        /// the layout of the channels and |SampleRate| is the stream sample rate.
        /// |FramesPerBuffer| is the maximum number of frames that will occur in the
        /// PCM packet passed to OnAudioStreamPacket.
        /// </summary>
        /// <remarks>
        /// See also the original CEF documentation in
        /// <see href="https://bitbucket.org/chromiumfx/chromiumfx/src/tip/cef/include/capi/cef_audio_handler_capi.h">cef/include/capi/cef_audio_handler_capi.h</see>.
        /// </remarks>
        public event CfxOnAudioStreamStartedEventHandler OnAudioStreamStarted {
            add {
                lock(eventLock) {
                    if(m_OnAudioStreamStarted == null) {
                        CfxApi.AudioHandler.cfx_audio_handler_set_callback(NativePtr, 0, on_audio_stream_started_native_ptr);
                    }
                    m_OnAudioStreamStarted += value;
                }
            }
            remove {
                lock(eventLock) {
                    m_OnAudioStreamStarted -= value;
                    if(m_OnAudioStreamStarted == null) {
                        CfxApi.AudioHandler.cfx_audio_handler_set_callback(NativePtr, 0, IntPtr.Zero);
                    }
                }
            }
        }

        private CfxOnAudioStreamStartedEventHandler m_OnAudioStreamStarted;

        /// <summary>
        /// Called when a PCM packet is received for the stream identified by
        /// |AudioStreamId|. |Data| is an array representing the raw PCM data as a
        /// floating point type, i.e. 4-byte value(s). |Frames| is the number of frames
        /// in the PCM packet. |Pts| is the presentation timestamp (in milliseconds
        /// since the Unix Epoch) and represents the time at which the decompressed
        /// packet should be presented to the user. Based on |Frames| and the
        /// |ChannelLayout| value passed to OnAudioStreamStarted you can calculate the
        /// size of the |Data| array in bytes.
        /// </summary>
        /// <remarks>
        /// See also the original CEF documentation in
        /// <see href="https://bitbucket.org/chromiumfx/chromiumfx/src/tip/cef/include/capi/cef_audio_handler_capi.h">cef/include/capi/cef_audio_handler_capi.h</see>.
        /// </remarks>
        public event CfxOnAudioStreamPacketEventHandler OnAudioStreamPacket {
            add {
                lock(eventLock) {
                    if(m_OnAudioStreamPacket == null) {
                        CfxApi.AudioHandler.cfx_audio_handler_set_callback(NativePtr, 1, on_audio_stream_packet_native_ptr);
                    }
                    m_OnAudioStreamPacket += value;
                }
            }
            remove {
                lock(eventLock) {
                    m_OnAudioStreamPacket -= value;
                    if(m_OnAudioStreamPacket == null) {
                        CfxApi.AudioHandler.cfx_audio_handler_set_callback(NativePtr, 1, IntPtr.Zero);
                    }
                }
            }
        }

        private CfxOnAudioStreamPacketEventHandler m_OnAudioStreamPacket;

        /// <summary>
        /// Called when the stream identified by |AudioStreamId| has stopped.
        /// OnAudioSteamStopped will always be called after OnAudioStreamStarted; both
        /// functions may be called multiple times for the same stream.
        /// </summary>
        /// <remarks>
        /// See also the original CEF documentation in
        /// <see href="https://bitbucket.org/chromiumfx/chromiumfx/src/tip/cef/include/capi/cef_audio_handler_capi.h">cef/include/capi/cef_audio_handler_capi.h</see>.
        /// </remarks>
        public event CfxOnAudioStreamStoppedEventHandler OnAudioStreamStopped {
            add {
                lock(eventLock) {
                    if(m_OnAudioStreamStopped == null) {
                        CfxApi.AudioHandler.cfx_audio_handler_set_callback(NativePtr, 2, on_audio_stream_stopped_native_ptr);
                    }
                    m_OnAudioStreamStopped += value;
                }
            }
            remove {
                lock(eventLock) {
                    m_OnAudioStreamStopped -= value;
                    if(m_OnAudioStreamStopped == null) {
                        CfxApi.AudioHandler.cfx_audio_handler_set_callback(NativePtr, 2, IntPtr.Zero);
                    }
                }
            }
        }

        private CfxOnAudioStreamStoppedEventHandler m_OnAudioStreamStopped;

        internal override void OnDispose(IntPtr nativePtr) {
            if(m_OnAudioStreamStarted != null) {
                m_OnAudioStreamStarted = null;
                CfxApi.AudioHandler.cfx_audio_handler_set_callback(NativePtr, 0, IntPtr.Zero);
            }
            if(m_OnAudioStreamPacket != null) {
                m_OnAudioStreamPacket = null;
                CfxApi.AudioHandler.cfx_audio_handler_set_callback(NativePtr, 1, IntPtr.Zero);
            }
            if(m_OnAudioStreamStopped != null) {
                m_OnAudioStreamStopped = null;
                CfxApi.AudioHandler.cfx_audio_handler_set_callback(NativePtr, 2, IntPtr.Zero);
            }
            base.OnDispose(nativePtr);
        }
    }


    namespace Event {

        /// <summary>
        /// Called when the stream identified by |AudioStreamId| has started.
        /// |AudioStreamId| will uniquely identify the stream across all future
        /// CfxAudioHandler callbacks. OnAudioSteamStopped will always be called
        /// after OnAudioStreamStarted; both functions may be called multiple times for
        /// the same stream. |Channels| is the number of channels, |ChannelLayout| is
        /// the layout of the channels and |SampleRate| is the stream sample rate.
        /// |FramesPerBuffer| is the maximum number of frames that will occur in the
        /// PCM packet passed to OnAudioStreamPacket.
        /// </summary>
        /// <remarks>
        /// See also the original CEF documentation in
        /// <see href="https://bitbucket.org/chromiumfx/chromiumfx/src/tip/cef/include/capi/cef_audio_handler_capi.h">cef/include/capi/cef_audio_handler_capi.h</see>.
        /// </remarks>
        public delegate void CfxOnAudioStreamStartedEventHandler(object sender, CfxOnAudioStreamStartedEventArgs e);

        /// <summary>
        /// Called when the stream identified by |AudioStreamId| has started.
        /// |AudioStreamId| will uniquely identify the stream across all future
        /// CfxAudioHandler callbacks. OnAudioSteamStopped will always be called
        /// after OnAudioStreamStarted; both functions may be called multiple times for
        /// the same stream. |Channels| is the number of channels, |ChannelLayout| is
        /// the layout of the channels and |SampleRate| is the stream sample rate.
        /// |FramesPerBuffer| is the maximum number of frames that will occur in the
        /// PCM packet passed to OnAudioStreamPacket.
        /// </summary>
        /// <remarks>
        /// See also the original CEF documentation in
        /// <see href="https://bitbucket.org/chromiumfx/chromiumfx/src/tip/cef/include/capi/cef_audio_handler_capi.h">cef/include/capi/cef_audio_handler_capi.h</see>.
        /// </remarks>
        public class CfxOnAudioStreamStartedEventArgs : CfxEventArgs {

            internal IntPtr m_browser;
            internal CfxBrowser m_browser_wrapped;
            internal int m_audio_stream_id;
            internal int m_channels;
            internal int m_channel_layout;
            internal int m_sample_rate;
            internal int m_frames_per_buffer;

            internal CfxOnAudioStreamStartedEventArgs() {}

            /// <summary>
            /// Get the Browser parameter for the <see cref="CfxAudioHandler.OnAudioStreamStarted"/> callback.
            /// </summary>
            public CfxBrowser Browser {
                get {
                    CheckAccess();
                    if(m_browser_wrapped == null) m_browser_wrapped = CfxBrowser.Wrap(m_browser);
                    return m_browser_wrapped;
                }
            }
            /// <summary>
            /// Get the AudioStreamId parameter for the <see cref="CfxAudioHandler.OnAudioStreamStarted"/> callback.
            /// </summary>
            public int AudioStreamId {
                get {
                    CheckAccess();
                    return m_audio_stream_id;
                }
            }
            /// <summary>
            /// Get the Channels parameter for the <see cref="CfxAudioHandler.OnAudioStreamStarted"/> callback.
            /// </summary>
            public int Channels {
                get {
                    CheckAccess();
                    return m_channels;
                }
            }
            /// <summary>
            /// Get the ChannelLayout parameter for the <see cref="CfxAudioHandler.OnAudioStreamStarted"/> callback.
            /// </summary>
            public CfxChannelLayout ChannelLayout {
                get {
                    CheckAccess();
                    return (CfxChannelLayout)m_channel_layout;
                }
            }
            /// <summary>
            /// Get the SampleRate parameter for the <see cref="CfxAudioHandler.OnAudioStreamStarted"/> callback.
            /// </summary>
            public int SampleRate {
                get {
                    CheckAccess();
                    return m_sample_rate;
                }
            }
            /// <summary>
            /// Get the FramesPerBuffer parameter for the <see cref="CfxAudioHandler.OnAudioStreamStarted"/> callback.
            /// </summary>
            public int FramesPerBuffer {
                get {
                    CheckAccess();
                    return m_frames_per_buffer;
                }
            }

            public override string ToString() {
                return String.Format("Browser={{{0}}}, AudioStreamId={{{1}}}, Channels={{{2}}}, ChannelLayout={{{3}}}, SampleRate={{{4}}}, FramesPerBuffer={{{5}}}", Browser, AudioStreamId, Channels, ChannelLayout, SampleRate, FramesPerBuffer);
            }
        }

        /// <summary>
        /// Called when a PCM packet is received for the stream identified by
        /// |AudioStreamId|. |Data| is an array representing the raw PCM data as a
        /// floating point type, i.e. 4-byte value(s). |Frames| is the number of frames
        /// in the PCM packet. |Pts| is the presentation timestamp (in milliseconds
        /// since the Unix Epoch) and represents the time at which the decompressed
        /// packet should be presented to the user. Based on |Frames| and the
        /// |ChannelLayout| value passed to OnAudioStreamStarted you can calculate the
        /// size of the |Data| array in bytes.
        /// </summary>
        /// <remarks>
        /// See also the original CEF documentation in
        /// <see href="https://bitbucket.org/chromiumfx/chromiumfx/src/tip/cef/include/capi/cef_audio_handler_capi.h">cef/include/capi/cef_audio_handler_capi.h</see>.
        /// </remarks>
        public delegate void CfxOnAudioStreamPacketEventHandler(object sender, CfxOnAudioStreamPacketEventArgs e);

        /// <summary>
        /// Called when a PCM packet is received for the stream identified by
        /// |AudioStreamId|. |Data| is an array representing the raw PCM data as a
        /// floating point type, i.e. 4-byte value(s). |Frames| is the number of frames
        /// in the PCM packet. |Pts| is the presentation timestamp (in milliseconds
        /// since the Unix Epoch) and represents the time at which the decompressed
        /// packet should be presented to the user. Based on |Frames| and the
        /// |ChannelLayout| value passed to OnAudioStreamStarted you can calculate the
        /// size of the |Data| array in bytes.
        /// </summary>
        /// <remarks>
        /// See also the original CEF documentation in
        /// <see href="https://bitbucket.org/chromiumfx/chromiumfx/src/tip/cef/include/capi/cef_audio_handler_capi.h">cef/include/capi/cef_audio_handler_capi.h</see>.
        /// </remarks>
        public class CfxOnAudioStreamPacketEventArgs : CfxEventArgs {

            internal IntPtr m_browser;
            internal CfxBrowser m_browser_wrapped;
            internal int m_audio_stream_id;
            internal IntPtr m_data;
            internal int m_frames;
            internal long m_pts;

            internal CfxOnAudioStreamPacketEventArgs() {}

            /// <summary>
            /// Get the Browser parameter for the <see cref="CfxAudioHandler.OnAudioStreamPacket"/> callback.
            /// </summary>
            public CfxBrowser Browser {
                get {
                    CheckAccess();
                    if(m_browser_wrapped == null) m_browser_wrapped = CfxBrowser.Wrap(m_browser);
                    return m_browser_wrapped;
                }
            }
            /// <summary>
            /// Get the AudioStreamId parameter for the <see cref="CfxAudioHandler.OnAudioStreamPacket"/> callback.
            /// </summary>
            public int AudioStreamId {
                get {
                    CheckAccess();
                    return m_audio_stream_id;
                }
            }
            /// <summary>
            /// Get the Data parameter for the <see cref="CfxAudioHandler.OnAudioStreamPacket"/> callback.
            /// </summary>
            public IntPtr Data {
                get {
                    CheckAccess();
                    return m_data;
                }
            }
            /// <summary>
            /// Get the Frames parameter for the <see cref="CfxAudioHandler.OnAudioStreamPacket"/> callback.
            /// </summary>
            public int Frames {
                get {
                    CheckAccess();
                    return m_frames;
                }
            }
            /// <summary>
            /// Get the Pts parameter for the <see cref="CfxAudioHandler.OnAudioStreamPacket"/> callback.
            /// </summary>
            public long Pts {
                get {
                    CheckAccess();
                    return m_pts;
                }
            }

            public override string ToString() {
                return String.Format("Browser={{{0}}}, AudioStreamId={{{1}}}, Data={{{2}}}, Frames={{{3}}}, Pts={{{4}}}", Browser, AudioStreamId, Data, Frames, Pts);
            }
        }

        /// <summary>
        /// Called when the stream identified by |AudioStreamId| has stopped.
        /// OnAudioSteamStopped will always be called after OnAudioStreamStarted; both
        /// functions may be called multiple times for the same stream.
        /// </summary>
        /// <remarks>
        /// See also the original CEF documentation in
        /// <see href="https://bitbucket.org/chromiumfx/chromiumfx/src/tip/cef/include/capi/cef_audio_handler_capi.h">cef/include/capi/cef_audio_handler_capi.h</see>.
        /// </remarks>
        public delegate void CfxOnAudioStreamStoppedEventHandler(object sender, CfxOnAudioStreamStoppedEventArgs e);

        /// <summary>
        /// Called when the stream identified by |AudioStreamId| has stopped.
        /// OnAudioSteamStopped will always be called after OnAudioStreamStarted; both
        /// functions may be called multiple times for the same stream.
        /// </summary>
        /// <remarks>
        /// See also the original CEF documentation in
        /// <see href="https://bitbucket.org/chromiumfx/chromiumfx/src/tip/cef/include/capi/cef_audio_handler_capi.h">cef/include/capi/cef_audio_handler_capi.h</see>.
        /// </remarks>
        public class CfxOnAudioStreamStoppedEventArgs : CfxEventArgs {

            internal IntPtr m_browser;
            internal CfxBrowser m_browser_wrapped;
            internal int m_audio_stream_id;

            internal CfxOnAudioStreamStoppedEventArgs() {}

            /// <summary>
            /// Get the Browser parameter for the <see cref="CfxAudioHandler.OnAudioStreamStopped"/> callback.
            /// </summary>
            public CfxBrowser Browser {
                get {
                    CheckAccess();
                    if(m_browser_wrapped == null) m_browser_wrapped = CfxBrowser.Wrap(m_browser);
                    return m_browser_wrapped;
                }
            }
            /// <summary>
            /// Get the AudioStreamId parameter for the <see cref="CfxAudioHandler.OnAudioStreamStopped"/> callback.
            /// </summary>
            public int AudioStreamId {
                get {
                    CheckAccess();
                    return m_audio_stream_id;
                }
            }

            public override string ToString() {
                return String.Format("Browser={{{0}}}, AudioStreamId={{{1}}}", Browser, AudioStreamId);
            }
        }

    }
}
