(function(a,c){typeof define==="function"&&define.amd?define([],c):a.Async=c()})(this,function(){return function(){return{parallel:function(a,c){for(var f=a.length,d=a.length,e=[],g=false,b=0;b<d;b++)(function(b){a[b](function(a,d){a?g||(g=true,c(a,e)):(f--,e[b]=d,f||c(null,e))})})(b)}}}()});
