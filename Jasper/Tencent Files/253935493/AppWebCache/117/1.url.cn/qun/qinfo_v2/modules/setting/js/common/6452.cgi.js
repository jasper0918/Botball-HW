define(["jquery","./cookie"],function(i,k){var m=function(){var a=g.client.getSKey();if(typeof a!="string")return a;for(var c="",e=0,b=a.length;e<b;e+=2)c+=String.fromCharCode("0x"+a.slice(e,e+2));return c},n=function(a){for(var c=5381,e=0,b=a.length;e<b;++e)c+=(c<<5)+a.charAt(e).charCodeAt();return c&2147483647},o={maxReattemptCount:1,allowConcurrent:true,method:"post",splitKey:"",splitMax:1,client:null,vCode:null},g,p={from:"qinfo_v2"},q=function(){var a=m();return a&&a!=k.get("skey")||!g.client||
!g.client.getSelfUin()?(k.set("uin","o"+g.client.getSelfUin(),".qq.com"),k.set("skey",a,".qq.com"),true):false},r=function(a,c,e){if(!(a==="init"||a==="register")){var b=i.extend({},g,c),l=0;e[a]=function(d,c){if(b.allowConcurrent||!e[a].isProcessing){i.isFunction(d)&&(c=d,d={});var j=i.extend({},b.defaultParams,d);e[a].isProcessing=true;b.splitKey&&(j[b.splitKey]=j[b.splitKey].slice(0,b.splitMax).join("-"));j.bkn=k.bkn()||g.client&&n(m());i.ajax({url:b.url,type:b.method,dataType:"json",data:j,success:function(f){e[a].isProcessing=
false;if(b.vCode){var i=a!=="sendSms",h=b.vCode,k=h.isVisible();d.elevel&&h.unlock()}if(f.ec==0)l=0,c(f),i&&h.hide().clear(),!b.allowConcurrent&&b.splitKey&&d[b.splitKey].length>b.splitMax&&(d[b.splitKey]=d[b.splitKey].slice(b.splitMax),e[a](d,c));else if((f.ec===1||f.ec===4)&&l<b.maxReattemptCount)l++,g.client&&q()?e[a](d,c):c({ec:1});else if((f.ec===201||f.ec===202)&&b.vCode&&i){var j=f.ec===201;b.vCode.show(j,function(f,g){j?(d.elevel=2,d.vc=f):(d.elevel=4,d.phone=g,d.smsvc=f);b.vCode.lock();e[a](d,
c)},function(){c(f)})}else f.ec===203&&h?(h.refreshCodeImg(),h.showError("\u9a8c\u8bc1\u7801\u8f93\u5165\u6709\u8bef")):f.ec===204&&h?h.showError("\u9a8c\u8bc1\u7801\u8f93\u5165\u6709\u8bef"):(h&&k&&h.showError("\u7cfb\u7edf\u7e41\u5fd9,\u8bf7\u7a0d\u540e\u91cd\u8bd5"),c(f))},error:function(){e[a].isProcessing=false;if(b.vCode){var f=b.vCode;d.elevel&&f.unlock()}c({ec:500})}});b.allowConcurrent&&b.splitKey&&d[b.splitKey].length>b.splitMax&&(d[b.splitKey]=d[b.splitKey].slice(b.splitMax),e[a](d,c))}};
e[a].isProcessing=false}};return{init:function(a,c){g=i.extend({},o,c||{});g.defaultParams=i.extend({},p,g.defaultParams);this.register(a)},register:function(a){for(var c in a)a.hasOwnProperty(c)&&(typeof a[c]==="string"&&(a[c]={url:a[c]}),r(c,a[c],this))}}});
