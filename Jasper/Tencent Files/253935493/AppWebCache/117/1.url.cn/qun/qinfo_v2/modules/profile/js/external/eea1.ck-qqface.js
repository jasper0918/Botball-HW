(function(c,b){typeof define==="function"&&define.amd?define(["CKEDITOR","face","simple"],b):c.wordcount=b(c.CKEDITOR)})(this,function(c,b,a){c.plugins.add("qqface",{version:0.1,_editor:null,init:function(a){var b=this;this._editor=a;a.on("afterPaste",function(){Array.prototype.forEach.call(this.document.$.querySelectorAll("img"),function(a){a.getAttribute("rel")=="face"||a.getAttribute("rel")=="emoji"||a.remove()})},a,null,100);a.on("instanceReady",function(){b.createFace()});a.on("uiSpace",function(a){a.editor.filter.allow("img[src,alt,title,rel,width,height]",
"face")})},createFace:function(){function c(){e||(a.css.addClass(f,"cke_button_on"),a.css.removeClass(f,"cke_button_off"),b.show({parent:document.getElementById("base-info"),onSelect:function(a){var b=g._editor.document.$.getSelection().getRangeAt(0),c=g._editor.document.$.getSelection();if(b){var d=document.createTextNode("");b.insertNode(d);b.insertNode(a.dom);b.selectNode(d);c.removeAllRanges();c.addRange(b);g._editor.document.$.body.focus();h();setTimeout(function(){g._editor.fire("faceInsert")},
0)}}}),e=true)}function h(){e&&(b.hide(),a.css.removeClass(f,"cke_button_on"),a.css.addClass(f,"cke_button_off"),e=false)}var d=document.querySelector("#cke_"+this._editor.name+" #cke_wordcount_qun-intro"),d=d.parentNode.insertBefore(a.dom.getNode("span",{"class":"cke-qun-face cke_toolgroup"}),d),f=d.appendChild(a.dom.getNode("a",{href:"javascript:void(0)",title:"\u8868\u60c5","class":"cke_button cke_button__face  cke_button_off"}));f.appendChild(a.dom.getNode("span",{"class":"cke_button_icon cke_button__face_icon"}));
a.dom.getNode("span",{id:"cke-insert-face"});var e=false,g=this;this._face_span=d;d.addEventListener("click",function(a){!e?c():h();a.stopPropagation()});var i=function(){h()};this._editor.on("destroy",function(){document.removeEventListener("click",i)});document.addEventListener("click",i);this._editor.document.$.addEventListener("click",i)}})});