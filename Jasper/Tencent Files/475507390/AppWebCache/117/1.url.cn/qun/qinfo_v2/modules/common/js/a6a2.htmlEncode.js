(function(f,d){typeof define==="function"&&define.amd?define([],d):f.htmlEncode=d()})(this,function(){function f(a,b,c){return!b&&!c?e[a]||a:String.fromCharCode(b||c)}function d(a){return g[a]}function j(a){for(var b=0;b<i.length;b++)a=a.replace(RegExp("<(/?\\s*"+i[b]+")[^>]*>","ig"),function(a,b){return b.match(/^\//)?"\n":""});return a.replace(/<\/?[^>]*>/gi,"").replace(RegExp("&nbsp;","gi")," ").replace(/\u200B/g,"").replace(/(\r\n|\n|\r)$/g,"")}var k=/&quot;|&lt;|&gt;|&amp;|&nbsp;|&apos;|&#(\d+);|&#(\d+)/g,
l=/['<> "&]/g,e={"&quot;":'"',"&lt;":"<","&gt;":">","&amp;":"&","&nbsp;":" "},m=/\u00a0/g,n=/<br\s*\/?>/ig,o=/\r?\n/g,p=/\s/g,g={},h;for(h in e)g[e[h]]=h;e["&apos;"]="'";g["'"]="&#39;";var i="li,del,ins,fieldset,legend,tr,th,caption,thead,tbody,tfoot,p,h[1-6],dl,dt,dd,ol,ul,dir,address,blockquote,center,hr,pre,form,textarea,table".split(",");return{encode:function(a){return a?(""+a).replace(l,d).replace(o,"<br/>").replace(p,"&nbsp;"):""},decode:function(a){return a?(""+a).replace(n,"\n").replace(k,
f).replace(m," "):""},encodeBase16:function(a){if(!a)return a;a+="";for(var b=[],c=0,d=a.length;c<d;c++)b.push(a.charCodeAt(c).toString(16).toUpperCase());return b.join("")},decodeBase16:function(){if(!str)return str;str+="";for(var a=[],b=0,c=str.length;b<c;b+=2)a.push(String.fromCharCode("0x"+str.slice(b,b+2)));return a.join("")},normalText:function(a){return j(a)},decodeForMobile:function(a){return(""+a).replace(/<br>/,"&lt;br&gt;").replace(RegExp("\u0014&amp;nbsp;"),"&nbsp;")}}});