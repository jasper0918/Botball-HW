(function(){function s(a){if(typeof a!=="string")return false;try{a=(JSON&&JSON.parse||function(a){return eval("("+a+")")})(a.replace(/[\u0000-\u001f]/g," "))}catch(b){return false}return a}function k(a,b,d){(new Image).src="http://badjs.qq.com/cgi-bin/js_report?level="+(d||4)+"&bid=176"+(b?"&mid="+b:"")+"&msg="+encodeURIComponent(a)+"|_|"+x+"|_|0"+y+"&r="+Math.random()}function m(){i&&(i=!c("Contact.IsOnline").online);return i}function t(a){i=!a;for(var b=0,d=g.length;b<d;b++)g[b](a)}function c(a,
b){var d;if(d=!a.match(z)){if(m())typeof(u=j.OFFLINE_TIPS)=="function"&&u();d=i}if(d)return false;d=A[a]||null;var c=true,e;if((e=B[a])&&e.t)e.l<=0||!e.l?e.b=+new Date+e.t:c=false,e.l=e.b-new Date;c&&d&&v(331058);if(e=window.external&&window.external.CallHummerApi){try{var n=e.apply(this,arguments)}catch(h){return c&&k("Incorrect Call by "+a+"("+b+") with Exception "+h.message,331059),false}j.ISREPORT&&d&&v(d.id);e=s(n);if(j.ISREPORT&&d&&d.e){var g;if(typeof e!="object"||e.errorCode)c&&k("Incorrect Data And ErrorCode by "+
a+"("+b+") with "+n,d.e);else if(g=d.c)for(var l in g)if(!(l in e)||e[l]===""||e[l]===null){c&&k("Incorrect Data by "+a+"("+b+") Property "+l+" with "+n,d.e);break}}return e}c&&k("Incorrect Call by "+a+" without Function CallHummerApi",331059);return false}function h(a,b,d){if(typeof a!="object")return a;var b=b||{},c;for(c in b){var e,g;a[c]=d&&typeof(e=a[c])==="function"&&typeof(g=b[c])==="function"?function(){g.apply(a,arguments)||e.apply(a,arguments)}:b[c]}}var w=this||window,j=w.CommonApi||(w.CommonApi=
{});j.version="0.1";var x=encodeURIComponent(window.location.href),y="|_|browser:[agent:"+navigator.userAgent+",plat:"+navigator.platform+",appcode:"+navigator.appCodeName+",appname:"+navigator.appName+",appversion:"+navigator.appVersion+"]",A={"Default.DataReport":{id:330981,e:331028},"Default.GetPerfTimeStamp":{id:330982,e:331029},"Window.Show":{id:330983,e:331030},"Window.Hide":{id:330984,e:331031},"Window.Close":{id:330985,e:331032},"Window.Maximize":{id:330986,e:331033},"Window.Minimize":{id:330987,
e:331034},"Window.Restore":{id:330988,e:331035},"Window.Resize":{id:330989,e:331036},"Window.Move":{id:330990,e:331037},"Window.SetTitle":{id:330991,e:331038},"Window.ReloadPage":{id:330992,e:331039},"Window.PopNewWebPage":{id:330993,e:331040},"Window.Alert":{id:330994,e:331041},"Window.Confirm":{id:330995,e:331042},"Contact.GetSelfUin":{id:330996,e:331043,c:{uin:"string"}},"Contact.GetNickName":{id:330997,e:331044,c:{nickName:"string"}},"Contact.IsOnline":{id:330998,e:331045},"Contact.SetRemark":{id:330999,
e:331046},"Contact.OpenContactInfoCard":{id:331E3,e:331047},"Contact.AddFriend":{id:331001,e:331048},"Contact.OpenChatSession":{id:331002,e:331049},"IM.GetVersion":{id:331003,e:331050,c:{version:"string"}},"IM.GetClientKey":{id:331004,e:331051,c:{clientKey:"string"}},"IM.GetSKey":{id:331005,e:331052,c:{sKey:"string"}},"Group.OpenGroupInfoCard":{id:331006,e:331053},"Group.JoinGroup":{id:331007,e:331054},"Misc.DownloadFile":{id:331008,e:331055},"Misc.OpenWebPic":{id:331009,e:331056},"Misc.ClipScreen":{id:331010,
e:331057}},v=function(){var a,b=[];return function(d,c){b.push("0-0-"+d+(typeof c=="number"?"_"+c:""));window.clearTimeout(a);a=window.setTimeout(function(){var a=new Image;a.onload=a.onerror=function(){a=this.onload=this.onerror=null};a.src="http://jsreport.qq.com/cgi-bin/report?id=176&rs="+b.join("|_|")+"&r="+Math.random();b=[]},1E3)}}(),z=/(Contact\.IsOnline)|(Window\.)/,i,g=[],o=[],p=[],q,r,u;h(window,{OnClientCall:function(a){a=s(a);if(a.type=="event")switch(a.cmd){case "OnQQOnlineEvt":t(true);
break;case "OnQQOfflineEvt":t(false);break;case "OnReceiveS2CMsg":for(var a=a.param,b=0,c=p.length;b<c;b++)p[b](a);break;case "CanCloseWindow":a:{a=true;b=0;for(c=o.length;b<c;b++)if(a=o[b](),!a)break a}}else if(a.type=="callback")switch(a.cmd){case "OnOpenWebPicEvt":q&&q(a.param);break;case "onClipScreenEvt":r&&r(a.param)}}},true);var B={"Window.Move":{t:200}};h(j,{dataReport:function(a){return c("Default.DataReport",'{ "bigt" : "'+a+'" }')},getPerfTimeStamp:function(){return c("Default.GetPerfTimeStamp")},
show:function(){return c("Window.Show")},hide:function(){return c("Window.Hide")},close:function(){return c("Window.Close")},maximize:function(){return c("Window.Maximize")},minimize:function(){return c("Window.Minimize")},restore:function(){return c("Window.Restore")},resize:function(a,b){return c("Window.Resize",'{ "width" : '+a+', "height" : '+b+" }")},move:function(a,b){return c("Window.Move",'{ "offsetX" : '+a+', "offsetY" : '+b+" }")},setTitle:function(a){return c("Window.SetTitle",'{ "title" : "'+
a+'" }')},reloadPage:function(){return c("Window.ReloadPage")},popNewWebPage:function(a,b,d,f){return c("Window.PopNewWebPage",'{ "width" : '+a+', "height" : '+b+', "title" : "'+f+'", "url" : "'+d+'" }')},alert:function(a,b,d){return c("Window.Alert",'{ "iconType" : '+a+', "title" : "'+b+'", "text" : "'+d+'" }')},confirm:function(a,b,d){return c("Window.Confirm",'{ "iconType" : '+a+', "title" : "'+b+'", "text" : "'+d+'" }')},getSelfUin:function(){return c("Contact.GetSelfUin").uin},getNickname:function(a){return c("Contact.GetNickName",
'{ "uin" : "'+a+'" }')},isOnline:function(){return!m()},isOffline:m,setRemark:function(a,b){return c("Contact.SetRemark",'{ "uin" : "'+a+'", "remark" : "'+b+'" }')},openContactInfoCard:function(a,b){return c("Contact.OpenContactInfoCard",'{ "uin" : "'+a+'", "tabId" : '+b+" }")},addFriend:function(a,b){return c("Contact.AddFriend",'{ "uin" : "'+a+'", "name" : "'+b+'" }')},openChatSession:function(a){return c("Contact.OpenChatSession",'{ "uin" : "'+a+'" }')},getVersion:function(){return c("IM.GetVersion")},
getClientKey:function(){return c("IM.GetClientKey")},getSKey:function(){for(var a=c("IM.GetSKey"),b=a&&a.sKey,d=[],f=0,e=b.length;f<e;f+=2)d.push(String.fromCharCode("0x"+b.slice(f,f+2)));a.skey=d.join("");return a},openGroupInfoCard:function(a,b){return c("Group.OpenGroupInfoCard",'{ "groupId" : "'+a+'", "tabId" : '+b+" }")},joinGroup:function(a){return c("Group.JoinGroup",'{ "groupId" : "'+a+'" }')},downloadFile:function(a,b,d){return c("Misc.DownloadFile",'{ "url" : "'+a+'", "fileName" : "'+b+
'", "fileSize" : "'+d+'" }')},openWebPic:function(a,b){q=b;return c("Misc.OpenWebPic",'{ "url" : "'+a+'", "function" : "OnOpenWebPicEvt" }')},clipScreen:function(a,b,d,f,e){r=e;return c("Misc.ClipScreen",'{ "url" : "'+d+'", "cookies" : "'+a+'", "parameters" : "'+b+'", "method" : "'+f+'", "uploaded" : "onClipScreenEvt" }')},onQQStateChange:function(a){typeof a==="function"&&g.push(a)},onCanCloseWindow:function(a){typeof a==="function"&&o.push(a)},onReceiveS2CMsg:function(a){typeof a==="function"&&
p.push(a)},extend:function(a,b,c,f){var e=Object.prototype.toString.call(a);e==="[object String]"?(e={},e[a]=b,h(c||this,e,f)):e==="[object Object]"&&((b===null||b===void 0)&&arguments.length>=4?c=c||this:(f=c,c=b||this),h(c,a,f))},OFFLINE_TIPS:function(){},ISREPORT:true})})();
