define([],function(){var h=function(e,f){function h(){var b=[],a;for(a in c){var d=i[a];b.push(d[0]+"-"+c[a]+"-"+(d[1]||"0")+"_"+c[a]+(d[2]?"-"+d[2]:""))}if(b.length>0)b=j+b.join("|_|")+"&"+(new Date).getTime(),a=new Image,a.src=b,a.onload=a.onerror=null,c={}}var c={},i=f||{},j="http://jsreport.qq.com/cgi-bin/report?id="+e+"&rs=",g;this.report=function(b,a,d){i[b]&&(c[b]=(c[b]||0)+(typeof a=="number")?a:1,g&&clearTimeout(g),g=setTimeout(h,d?0:1E3))}};return{init:function(e,f){return new h(e,f)}}});
