(function(f,g){typeof define==="function"&&define.amd?define(["simple"],g):f.selectionPatch=g($)})(this,function(f){var g=function(e,f,b){for(var d=0,a=0,c=0,c=0;c<e.length;c++)if(e.charCodeAt(c)>255?a+=2:a++,a<=f)d++;else if(a>f+b)break;return e.substring(d,c)},k=function(f,g,b){for(var d=0,a=0,c=0,c=0;c<f.length;c++)if(f.charCodeAt(c)>255?a+=3:a++,a<=g)d++;else if(a>g+b)break;return f.substring(d,c)};return function(e){var j=function(b){var d="";if(window.getSelection)d=b.value.slice(b.selectionStart,
b.selectionEnd);else if(document.selection)d=document.selection.createRange().text;return d};e.addInputState=function(b,d,a){var a=a||{},c={type:"text"};if("maxlength"in a||"maxLength"in a)c.maxlength=a.maxlength||a.maxLength;if("id"in a)c.id=a.id;a=f.dom.getNode("input",c);a.value=d;b.appendChild(a);e.limitInputLength(a,c.maxlength)};e.limitInputLength=function(b,d,a){var a=a||3,c=[8,9,20,33,34,35,36,37,38,39,40,46,16,17],e;b.onpaste=function(c){var e=c.clipboardData?c.clipboardData.getData("Text"):
"";if(e){j(b);var i=b.value,e=i.slice(0,b.selectionStart)+e+i.slice(b.selectionEnd);if(f.str.byteLen(e,a)>d)b.selectionEnd==i.length?(b.value=a==3?k(e,0,d):g(e,0,d),f.e.trigger(b,"input"),b.selectionStart=b.selectionEnd):c.preventDefault()}};f.e.add(b,"keydown",function(h){!h.ctrlKey&&c.indexOf(h.keyCode)==-1&&f.str.byteLen(b.value,a)>=d&&j(b).length==0&&h.preventDefault();clearTimeout(e);e=setTimeout(function(){if(f.str.byteLen(b.value,a)>d)b.value=a==3?k(b.value,0,d):g(b.value,0,d),f.e.trigger(b,
"input")},0)})}}});