(function(b,d){typeof define==="function"&&define.amd?define(["./selectionPatch","./tmplPatch"],d):b.Util=d(b.selectionPatch,b.tmplPatch)})(this,function(b,d){var g={func:{throttle:function(e,a,c){var a=a||3E3,h=0,i,f,b=function(){f=arguments.length>0?arguments:f;var d=(new Date).getTime(),g=d-h;g>=a?(e.apply(c,f),h=d):(clearTimeout(i),i=setTimeout(function(){b.apply(c,f)},a-g))};return b}},getBkn:function(){var e=$.cookie.get("skey"),a="";if(e){for(var a=5381,c=0,b=e.length;c<b;++c)a+=(a<<5)+e.charAt(c).charCodeAt();
a&=2147483647}return a},urlencode:function(e){var a=[],c;for(c in e)a.push(c+"="+encodeURIComponent(e[c]));return a.join("&")},genRandomArray:function(e){for(var a=0,c=[],b=e.length,d=0,f=[];a<b;a++)f.push(e[a]);for(a=0;a<b;a++)d=Math.floor(Math.random()*(b-a)),c.push(f[d]),f.splice(d,1);return c}};b(g);d(g);return g});