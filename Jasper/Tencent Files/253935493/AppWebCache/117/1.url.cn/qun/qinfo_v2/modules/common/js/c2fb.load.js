var LoadCSS=function(){function g(b,a){for(var c=-1,e=0,f=b.length;e<f;e++)b[e]==a&&(c=e);return c}function j(b,a){for(var c=k.length;c>0;c--)if(k[c-1].href===b.href){f(b.href,a);return}b.pollCount++;b.pollCount<200?setTimeout(function(){j(b,a)},50):f(b.href,a)}function f(b,a){var c=g(a.urls,b);a.urls.splice(c,1);a.urls.length||(a.callback(a.obj),c=g(i,a),i.splice(c,1))}function l(b,a,c){var e={urls:b,callback:a,obj:c};i.push(e);b=e.urls;a=0;for(c=b.length;a<c;++a){var g=b[a],d;h.gecko?d=document.createElement("style"):
(d=document.createElement("link"),d.rel="stylesheet",d.href=g);h.gecko||h.webkit?(d.pollCount=0,e.urls[a]=d.href,h.webkit?j(d,e):(d.innerHTML='@import "'+g+'";',f(d.href,e))):d.onload=d.onerror=function(){f(this.href,e)};m.appendChild(d)}}var m=document.head||document.getElementsByTagName("head")[0],k=document.styleSheets,h=function(){var b=navigator.userAgent,a={};(a.webkit=/AppleWebKit\//.test(b))||(a.ie=/MSIE/.test(b))||(a.opera=/Opera/.test(b))||(a.gecko=/Gecko\//.test(b))||(a.unknown=true);return a}(),
i=[];return{load:function(b,a,c){l([].concat(b),a||function(){},c||{})}}}();