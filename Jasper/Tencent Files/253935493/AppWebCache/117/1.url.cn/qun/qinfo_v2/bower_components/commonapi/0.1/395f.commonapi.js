(function(){function o(a){if(typeof a!=="string")return false;try{a=(JSON&&JSON.parse||function(a){return eval("("+a+")")})(a.replace(/[\u0000-\u001f]/g," "))}catch(b){return false}return a}function g(){return h=!d("Contact.IsOnline").online}function p(a){h=!a;for(var b=0,c=i.length;b<c;b++)i[b](a)}function d(a,b){var c;if(c=!a.match(s)){if(g())typeof(q=j.OFFLINE_TIPS)=="function"&&q();c=h}if(c)return false;if(c=window.external&&window.external.CallHummerApi){try{data=c.apply(this,arguments),data=
o(data)}catch(d){return false}return data}return false}function r(a,b){if(typeof a!="object")return a;var b=b||{},c;for(c in b)a[c]=b[c]}var k=this||window,j=k.CommonApi||(k.CommonApi={});j.version="0.1";var s=/(Contact\.IsOnline)|(Window\.)/,h,i=[],l=[],e=[],m,n,q;k.OnClientCall=function(a){a=o(a);if(a.type=="event")switch(a.cmd){case "OnQQOnlineEvt":p(true);break;case "OnQQOfflineEvt":p(false);break;case "OnReceiveS2CMsg":for(var a=a.param,b=0,c=e.length;b<c;b++)e[b](a);break;case "CanCloseWindow":a:{a=
true;b=0;for(c=l.length;b<c;b++)if(a=l[b](),!a)break a}}else if(a.type=="callback")switch(a.cmd){case "OnOpenWebPicEvt":m&&m(a.param);break;case "onClipScreenEvt":n&&n(a.param)}};r(j,{dataReport:function(a){return d("Default.DataReport",'{ "bigt" : "'+a+'" }')},getPerfTimeStamp:function(){return d("Default.GetPerfTimeStamp")},groupPopNewWebPage:function(a,b,c,f,e){return d("Group.PopNewWebPage",'{"width" : '+a+', "height" : '+b+', "title" : "'+f+'", "url" : "'+c+'", "singletonId":"'+e+'" }')},show:function(){return d("Window.Show")},
hide:function(){return d("Window.Hide")},close:function(){return d("Window.Close")},maximize:function(){return d("Window.Maximize")},minimize:function(){return d("Window.Minimize")},restore:function(){return d("Window.Restore")},resize:function(a,b){return d("Window.Resize",'{ "width" : '+a+', "height" : '+b+" }")},move:function(a,b){return d("Window.Move",'{ "offsetX" : '+a+', "offsetY" : '+b+" }")},setTitle:function(a){return d("Window.SetTitle",'{ "title" : "'+a+'" }')},reloadPage:function(){return d("Window.ReloadPage")},
popNewWebPage:function(a,b,c,f){return d("Window.PopNewWebPage",'{ "width" : '+a+', "height" : '+b+', "title" : "'+f+'", "url" : "'+c+'" }')},alert:function(a,b,c){return d("Window.Alert",'{ "iconType" : '+a+', "title" : "'+b+'", "text" : "'+c+'" }')},confirm:function(a,b,c){return d("Window.Confirm",'{ "iconType" : '+a+', "title" : "'+b+'", "text" : "'+c+'" }')},getSelfUin:function(){return d("Contact.GetSelfUin").uin},getNickname:function(a){return d("Contact.GetNickName",'{ "uin" : "'+a+'" }')},
isOnline:function(){return!g()},isOffline:g,setRemark:function(a,b){return d("Contact.SetRemark",'{ "uin" : "'+a+'", "remark" : "'+b+'" }')},openContactInfoCard:function(a,b){return d("Contact.OpenContactInfoCard",'{ "uin" : "'+a+'", "tabId" : '+b+" }")},addFriend:function(a,b){return d("Contact.AddFriend",'{ "uin" : "'+a+'", "name" : "'+b+'" }')},openChatSession:function(a){return d("Contact.OpenChatSession",'{ "uin" : "'+a+'" }')},getVersion:function(){return d("IM.GetVersion")},getClientKey:function(){return d("IM.GetClientKey")},
getSKey:function(){for(var a=d("IM.GetSKey"),b=a&&a.sKey,c=[],f=0,e=b.length;f<e;f+=2)c.push(String.fromCharCode("0x"+b.slice(f,f+2)));a.skey=c.join("");return a},openGroupInfoCard:function(a,b){return d("Group.OpenGroupInfoCard",'{ "groupId" : "'+a+'", "tabId" : '+b+" }")},joinGroup:function(a){return d("Group.JoinGroup",'{ "groupId" : "'+a+'" }')},downloadFile:function(a,b,c){return d("Misc.DownloadFile",'{ "url" : "'+a+'", "fileName" : "'+b+'", "fileSize" : "'+c+'" }')},openWebPic:function(a,b){m=
b;return d("Misc.OpenWebPic",'{ "url" : "'+a+'", "function" : "OnOpenWebPicEvt" }')},clipScreen:function(a,b,c,f,e){n=e;return d("Misc.ClipScreen",'{ "url" : "'+c+'", "cookies" : "'+a+'", "parameters" : "'+b+'", "method" : "'+f+'", "uploaded" : "onClipScreenEvt" }')},onQQStateChange:function(a){typeof a==="function"&&i.push(a)},onCanCloseWindow:function(a){typeof a==="function"&&l.push(a)},onReceiveS2CMsg:function(a){typeof a==="function"&&e.push(a)},offReceiveS2CMsg:function(a){a=e.indexOf(a);a!=
-1&&e.splice(a,1)},extend:function(a,b){var c=Object.prototype.toString.call(a);c==="[object String]"?this[a]=b:c==="[object Object]"&&r(this,a)},debug:function(a){var b=document.createElement("p");b.innerHTML=a;document.body.insertBefore(b,document.body.childNodes[0])}})})();
