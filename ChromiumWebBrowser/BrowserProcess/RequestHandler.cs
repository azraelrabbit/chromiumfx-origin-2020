// Copyright (c) 2014-2017 Wolfgang Borgsmüller
// All rights reserved.
// 
// This software may be modified and distributed under the terms
// of the BSD license. See the License.txt file for details.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using Chromium.Event;

namespace Chromium.WebBrowser {
    internal class RequestHandler : CfxRequestHandler {

        internal BrowserClient client;

        private CfxResourceRequestHandler resourceRequestHandler;

        internal RequestHandler(BrowserClient client) {
            this.client = client;
            resourceRequestHandler = new CfxResourceRequestHandler();
            this.GetResourceRequestHandler += RequestHandler_GetResourceRequestHandler;
            resourceRequestHandler.GetResourceHandler += ResourceRequestHandler_GetResourceHandler;
        }

        private void RequestHandler_GetResourceRequestHandler(object sender, CfxRequestHandlerGetResourceRequestHandlerEventArgs e) {
            if(client.browser.webResources.ContainsKey(e.Request.Url)) {
                e.DisableDefaultHandling = true;
                e.SetReturnValue(resourceRequestHandler);
            }
        }

        private void ResourceRequestHandler_GetResourceHandler(object sender, CfxGetResourceHandlerEventArgs e) {
            WebResource resource;
            if(client.browser.webResources.TryGetValue(e.Request.Url, out resource)) {
                e.SetReturnValue(resource.GetResourceHandler());
            }
        }
    }
}
