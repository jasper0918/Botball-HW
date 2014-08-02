(function(b,s){typeof define==="function"&&define.amd?define("simple,../common/client,./User,../common/util,./ActionBar,catCtrl,./InputSuggestion,./searchSuggestions,./DetailTrigger,../common/hintState".split(","),s):b.Panel=s(b.$,b.Client,b.User,b.Util,b.ActionBar,b.CatCtrl,b.InputSuggestion,b.searchSuggestions,b.DetailTrigger,b.HintState)})(this,function(b,s,g,l,t,k,w,x,y,m){function o(a,e,c){a=new w(a,e,c);z||(z=true,b.oop.addObserver(w,"fillQunDetail",function(){q()}));return a}function q(){var a=
b("qun-detail"),e=a.querySelector(".detail-trigger");if(e){var c;c=b("college-ipt");var f=[],a=a.querySelectorAll("input"),d=a.length;c&&b.css.hasClass(c.parentNode,"no-college-wrap")&&d--;var h="";for(c=0;c<d;c++)(h=b.str.trim(a[c].value))&&f.push(h);e.innerHTML=b.str.encodeHtml(f.join("-"));m.toggle("qun-detail",f.join());g.bSetDetail||t.enableSaveBtn()}}function u(a,e){var c=o(a,"select2",e);c.registerAfterOperations(function(a){this.searchMode=false;this.$ipt.value=a;this.name==="province"&&b.oop.notifyObservers(this,
"provinceChanged");q()});return c}function A(){if(typeof g.jCat=="undefined")return false;var a=g.jCat.id!==g.crtCatId||g.jSubcat.id!==g.crtSubcatId;if(!a)if(g.crtCatId===void 0||g.crtSubcatId===-1)a=false;else{var a=b("qun-detail").querySelectorAll("input"),e,c=a.length;e=b("college-ipt");var f=[];e&&b.css.hasClass(e.parentNode,"no-college-wrap")&&c--;for(e=0;e<c;e++)f.push(b.str.trim(a[e].value));a=f.join("-")!==g.fakeDesc}return a}function B(a,e,c){if(arguments.length>0)g.crtCatId=a,g.crtSubcatId=
e,g.fakeDesc=c;else{g.crtCatId=g.jCat.id;g.crtSubcatId=g.jSubcat.id;var f=b("qun-detail").querySelectorAll("input"),d,h=f.length;d=b("college-ipt");var i=[];d&&b.css.hasClass(d.parentNode,"no-college-wrap")&&h--;for(d=0;d<h;d++)i.push(b.str.trim(f[d].value));g.fakeDesc=i.join("-")}}function C(){v=true;var a=b("qun-detail");b.css.addClass(a.lastChild,"detail-trigger-disabled")}var z=false,v=false,j=function(){console.error("Error: [Panel]: unexpect internal call: getInfoFn!")};return{init:function(a){if(a&&
"getInfoFn"in a)j=a.getInfoFn},changeDetailState:function(){v=false;var a=g.jCat.id,e=g.jSubcat.id,c=b("qun-detail");c.removeChild(c.lastChild);var f="desc",d=null,h=null,d="",i=j("desc");if(e===-2){a===25?(f="games",d="LOL\u3001\u9b54\u517d\u3001QQ\u6e38\u620f\uff1f\u4f60\u4eec\u4e00\u8d77\u73a9\u7684\u6e38\u620f\u662f\uff1f"):a===26?(f="products",d="\u82f9\u679c\u3001\u5c3c\u5eb7\u3001\u5b9d\u9a6c\u3001\u9999\u5948\u5c14\uff1f\u4f60\u4eec\u70ed\u8877\u7684\u54c1\u724c\u662f\uff1f"):a===27&&(f="celebrity",
d="\u9648\u5955\u8fc5\u3001\u97e9\u5bd2\u3001\u674e\u5f00\u590d\u3001\u6797\u4e66\u8c6a\uff1f\u4f60\u4eec\u662f\u8c01\u7684\u7c89\u4e1d\uff1f");d=b.dom.getNode("input",{name:f,type:"text",maxLength:"40",placeholder:d,tabIndex:"1"});l.limitInputLength(d,40,2);h=b.dom.getNode("div",{"class":"detail-trigger-ctn trigger-ctn-single"});h.appendChild(d);c.appendChild(h);o(d,"suggest");if(g.bSetDetail)d.value=i;m.toggle("qun-detail",d.value);d.oninput=function(){t.enableSaveBtn();m.toggle("qun-detail",this.value)}}else if(d=
k.getSubIdArr(e),a=null,d.length===0)if(e===10012){d=b.dom.getNode("input",{name:f,type:"text",maxLength:"40",placeholder:"\u4f60\u4eec\u540c\u5728\u54ea\u5bb6\u516c\u53f8\u5de5\u4f5c\uff1f"});l.limitInputLength(d,40,2);h=b.dom.getNode("div",{"class":"detail-trigger-ctn trigger-ctn-single"});h.appendChild(d);c.appendChild(h);o(d,"suggest");if(g.bSetDetail)d.value=i;m.toggle("qun-detail",i);d.oninput=function(){t.enableSaveBtn();m.toggle("qun-detail",this.value)}}else if(e===10011){a=new y(c,{tabIndex:"1"});
a.$popView.innerHTML='<div class="schtype-wrap input-wrap"><input id="schtype-ipt" class="select-ipt" type="text" name="schooltype" placeholder="\u5728\u8bfb\u7c7b\u578b" maxlength="10"></div><div class="schname-wrap input-wrap"><input id="schname-ipt" type="text" name="school" placeholder="\u4f60\u4eec\u540c\u5728\u54ea\u6240\u5b66\u6821\uff1f" maxlength="40" tabIndex="1"/></div>                                                   <div class="second-detail no-college-wrap input-wrap"><input id="college-ipt" type="text" name="institute" placeholder="\u4f60\u4eec\u6240\u5728\u7684\u5b66\u9662\u662f\uff1f" maxlength="40" tabIndex="1"></div>';
var r=b("schtype-ipt"),p=b("college-ipt"),n=b("schname-ipt");l.limitInputLength(p,40,2);l.limitInputLength(n,40,2);o(r,"select");b("schtype-ipt").inputSuggestion.registerAfterOperations(function(a){b("schtype-ipt").setAttribute("aria-label","\u60a8\u5df2\u9009\u62e9"+a);a==="\u535a\u58eb"||a==="\u7855\u58eb"||a==="\u672c\u79d1"||a==="\u5927\u4e13"?(n.setAttribute("name","school"),b.css.removeClass(p.parentNode,"no-college-wrap")):(p.value="",b.css.addClass(p.parentNode,"no-college-wrap"),a==="\u9ad8\u4e2d"||
a==="\u4e2d\u4e13"||a==="\u521d\u4e2d"?n.setAttribute("name","highSchool"):a==="\u5c0f\u5b66"&&n.setAttribute("name","elementarySchool"));this.$ipt.value=a;q()});o(n,"suggest");o(p,"suggest");if(g.bSetDetail){e=j("desc").split(/\||-/);c=e[0]||"";r.value=c;n.value=e[1]||"";if(e[2])p.value=e[2];["\u9ad8\u4e2d","\u4e2d\u4e13","\u521d\u4e2d"].indexOf(c)!==-1?n.setAttribute("name","highSchool"):["\u535a\u58eb","\u7855\u58eb","\u672c\u79d1","\u5927\u4e13"].indexOf(c)!==-1?b.css.removeClass(p.parentNode,
"no-college-wrap"):e[0]==="\u5c0f\u5b66"&&n.setAttribute("name","elementarySchool");q()}}else(k.getItemById(e)||{}).n==="\u5176\u4ed6"?(h=b.dom.getNode("div",{"class":"detail-trigger-ctn trigger-ctn-single"}),d=b.dom.getNode("input",{name:"desc",type:"text",maxLength:"40"}),l.limitInputLength(d,40,2),d.value=g.bSetDetail?i:"",h.appendChild(d),c.appendChild(h),d.oninput=function(){t.enableSaveBtn();m.toggle("qun-detail",this.value)},m.toggle("qun-detail",d.value)):(h=b.dom.getNode("div",{"class":"detail-trigger-ctn"}),
c.appendChild(h),C(),m.toggle("qun-detail",""));else if(d.length>1){i=f=null;d="";h=null;a=new y(c,{tabIndex:"1"});if(e===10013||e===10014||e===10017)d="\u751f\u6d3b\u4f11\u95f2-\u540c\u57ce",e===10014?d="\u751f\u6d3b\u4f11\u95f2-\u540c\u4e61":e===10017&&(d="\u7f6e\u4e1a\u5b89\u5bb6-\u88c5\u4fee"),h=b.dom.getNode("div",{"class":"input-wrap"}),f=b.dom.getNode("input",{"class":"select-ipt",name:"province",data:d,maxLength:"40",type:"text",placeholder:"\u7701/\u76f4\u8f96\u5e02"}),l.limitInputLength(f,
40,2),h.appendChild(f),a.$popView.appendChild(h),u(f),h=b.dom.getNode("div",{"class":"input-wrap"}),i=b.dom.getNode("input",{"class":"select-ipt",name:"city",maxLength:"40",type:"text",placeholder:"\u5e02/\u533a"}),l.limitInputLength(i,40,2),h.appendChild(i),a.$popView.appendChild(h),r=u(i);else if(e===10015&&(d="\u7f6e\u4e1a\u5b89\u5bb6-\u4e1a\u4e3b",h=b.dom.getNode("div",{"class":"input-wrap"}),f=b.dom.getNode("input",{"class":"select-ipt",name:"province",data:d,maxLength:"40",type:"text",placeholder:"\u7701/\u76f4\u8f96\u5e02"}),
l.limitInputLength(f,40,2),h.appendChild(f),a.$popView.appendChild(h),u(f),h=b.dom.getNode("div",{"class":"input-wrap"}),i=b.dom.getNode("input",{"class":"select-ipt",name:"city",maxLength:"40",type:"text",placeholder:"\u5e02/\u533a"}),l.limitInputLength(i,40,2),h.appendChild(i),a.$popView.appendChild(h),r=u(i),x.setValue("provinceIpt",f),x.setValue("cityIpt",i),e=b.dom.getNode("div",{"class":"second-detail input-wrap"}),c=b.dom.getNode("input",{id:"building-ipt",type:"text",maxLength:"40",name:"building",
placeholder:"\u8fdc\u4eb2\u4e0d\u5982\u8fd1\u90bb\uff0c\u4f60\u4eec\u4f4f\u5728\u54ea\u4e2a\u5c0f\u533a\uff1f"}),l.limitInputLength(c,40,2),e.appendChild(c),o(c,"suggest"),a.$popView.appendChild(e),g.bSetDetail))c.value=j("desc");if(g.bSetDetail)e=k.getCatNamePath(j("catId")),f.value=e[2]||"",i.value=e[3]||"",e[2]&&r.refreshData(),q()}if(g.bSetDetail)B(),g.bSetDetail=false},getCatAndDetail:function(){var a=k.getCatNamePath(j("catId")),b={strCat:"",strDetail:""};if(a[0]!==void 0){var c=[];if(a[1]===
void 0){if(k.getSubIdArr(j("catId")).length===0)b.strDetail=j("desc");b.strCat=a[0]}else{var f=k.getSubcatId(j("catId")),c=k.getSubIdArr(f);if(c.length===0){if(f===10011||f===10012||(k.getItemById(f)||{}).n==="\u5176\u4ed6")f=j("desc").split(/[-\|]/),f=f.filter(function(a){if(a)return true}),b.strDetail=f.join("-")}else c=a[2]||"",a[3]&&(c=c+"-"+a[3]),f===10015&&j("desc")&&(c=c+"-"+j("desc")),b.strDetail=c;b.strCat=a[0]+"-"+a[1]}}return b},getModifyField:function(a){var e={};if(A()||a){var a=0,c=
"",c=g&&g.jSubcat&&g.jSubcat.id||0,f=b("qun-detail").querySelectorAll("input");if(c>0){var d=[];k.getSubIdArr(c).length===0?(a=c,c===10011?(d.push(f[0].value),d.push(f[1].value),b.css.hasClass(b("college-ipt").parentNode,"no-college-wrap")||d.push(f[2].value)):(c===10012||(k.getItemById(c)||{}).n==="\u5176\u4ed6")&&d.push(f[0].value)):(a=b.str.trim(f[0].value)+"-"+b.str.trim(f[1].value),a=k.getItemIdByPathStr(c,a),c===10015&&d.push(f[2].value));for(;d.length>0;)if(d.slice(-1)[0])break;else d.pop();
c=d.join("|")}else a=g.jCat.id,c=f[0]?b.str.trim(f[0].value):"";e.classID=a;e["class"]=c}v&&(e["class"]=null);return e},checkModify:A,checkValidation:function(){var a=true;g.jSubcat.id===-1?(g.jSubcat.mark(true),s.showTips("\u8bf7\u586b\u5199\u5b8c\u6574\u7684\u7fa4\u5206\u7c7b"),setTimeout(function(){g.catTrg.show()},0),a=false):g.jSubcat.mark(false);return a},storeDetail:B,disableDetail:C,getDetail:function(){var a="";if(v)a=null;else var a=b.dom.queryClass("detail-trigger","div",b("qun-detail")),
e=b("qun-detail").getElementsByTagName("input"),a=a?a.innerHTML:e.length&&e[0]?e[0].value:"";return a}}});