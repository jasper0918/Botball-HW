(function(a,b){typeof define==="function"&&define.amd?define([],b):a.Login=b()})(this,function(){return{notLoginCallback:function(a){var b;try{b=JSON.parse(top.external.Hummer_IM_GetClientKey()).clientKey,console.info("clientkey="+b)}catch(f){console.info("clientkey_catch_e")}var d=$.cookie.uin();if(b&&d){var c=document.createElement("iframe"),e=function(){a&&typeof a.succ=="function"&&a.succ();c.onload=null;$.e.remove(c,"load",e);document.body.removeChild(c);c=null};c.onload=e;c.src="http://ptlogin2.qq.com/jump?clientuin="+
d+"&clientkey="+b+"&u1="+encodeURIComponent("http://buluo.qq.com/loginproxy.html");document.body.appendChild(c)}else console.info("clientkey && clientUin not defined!"),a&&typeof a.err=="function"&&a.err()}}});