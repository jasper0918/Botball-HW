(function(a,c){typeof define==="function"&&define.amd?define(["simple"],c):a.TabIndexSwitcher=c()})(this,function(){return{init:function(a){this.arr=a;this.curIndex=-1},change:function(a){if(this.arr[a])this.curIndex!==-1&&this._forEach(this.arr[this.curIndex],function(a){a&&a.removeAttribute("tabIndex")}),this._forEach(this.arr[a],function(a,b){a&&a.setAttribute("tabIndex",b)}),this.curIndex=a},_forEach:function(a,c){var b,e,d;for(b=0;b<a.length;b++)if(d=eval("("+a[b][0]+")"),this._isType("NodeList")(d)||
this._isType("Array")(d))for(e=0;e<d.length;e++)c(d[e],a[b][1]);else c(d,a[b][1])},_isType:function(a){return function(c){return Object.prototype.toString.call(c)==="[object "+a+"]"}}}});