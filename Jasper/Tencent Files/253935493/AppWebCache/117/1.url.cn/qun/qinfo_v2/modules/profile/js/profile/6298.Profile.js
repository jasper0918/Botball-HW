(function(a,s){typeof define==="function"&&define.amd?define("simple,../common/TRecordPatch,../common/util,../common/client,./User,./LBS,./MapManage,./ActionBar,catCtrl,./Panel,./TabIndexSwitcher,./DetailTrigger,../../../common/js/util,../tags/tags,../../../common/js/log,./db_app,./Select,./InputSuggestion,../common/hintState,htmlEncode,face,xss,emojiface".split(","),s):a.Profile=s(a.$,a.TRecord,a.Util,a.Client,a.User,a.LBS,a.MapManage,a.ActionBar,a.CatCtrl,a.Panel,a.TabIndexSwitcher,a.DetailTrigger,
a.CommonUtil,a.Tags,a.LOG,a.DB,a.Select,a.InputSuggestion,a.HintState,a.htmlEncode,a.face,a.xss,a.emojiface)})(this,function(a,s,R,l,g,n,t,j,u,o,F,G,q,B,fa,C,S,D,p,x,y,T,U){var H,I;function ga(c){if(c&&"isEditing"in c)g.isEditing=c.isEditing;var b=a("qname"),f=a("intro-wrap"),c=a("qun-detail");if(!g.isEditing){g.isEditing=true;b.previousSibling.setAttribute("aria-label",d.gName);b.title=a.str.decodeHtml(d.gName);var w=T.filter(i.decodeRichText(i.getRichText())||a.str.decodeHtml(d.gIntro));w?(J=false,
a.css.removeClass(f,"no-intro"),a("intro-wrap-label").setAttribute("aria-label",w)):(J=true,f.innerHTML="-",a.css.addClass(f,"no-intro"),a("intro-wrap-label").setAttribute("aria-label","\u8fd9\u4e2a\u7fa4\u8fd8\u6ca1\u6709\u586b\u5199\u7fa4\u7b80\u4ecb"));var e=a("qun-cat-value"),h=a("qun-detail-value"),v=o.getCatAndDetail();a.oop.extend(ha,v||{});v.strCat==="\u540c\u4e8b\u670b\u53cb-\u540c\u5b66"?a.css.addClass(e,"max2lines"):a.css.removeClass(e,"max2lines");var z=v.strCat+(v.strDetail?"-"+v.strDetail:
"")||"-";W=!!z;e.setAttribute("title",z);e.innerHTML=a.str.encodeHtml(z);e.previousSibling.setAttribute("aria-label",z);p.toggle("qun-cat",z.replace(/\-/g,""));a.css.hide(c);h.title=v.strDetail;h.innerHTML=a.str.encodeHtml(v.strDetail)||"-";d.pos&&t.setVal(d.pos);if(g.hasPermission("editCat")&&!K&&(window.DEBUG||u.getCatNamePath(d.catId)[0]!=="\u540c\u4e8b\u670b\u53cb"&&d.gMemNum>=30)&&!K)n.LBSTip.init(a("profile-wrap")),K=true;h=a("qun-loc-value");e=n.get_lbs_str();n.set_lbs_html(h,{str:e,canedit:g.hasPermission("editCat")});
h.parentNode.previousSibling.setAttribute("aria-label",e);if(e===n.pseudoAddr||!e)(h=a("qun-loc").getElementsByClassName("del")[0])&&a.css.hide(h);F.change(0);p.toggle("qun-loc",e);b.removeAttribute("title");d.auth?(b.title="\u8ba4\u8bc1\u7fa4\u4e0d\u80fd\u4fee\u6539\u7fa4\u540d\u79f0",b.setAttribute("disabled","true")):(R.limitInputLength(a("qun-name"),X),a("qun-name").value=a.str.decodeHtml(d.gName),a("qun-name").oninput=function(){p.toggle("qun-name");j.enableSaveBtn()},p.toggle("qun-name"));if(!d.isSchoolGroup)f.removeAttribute("title"),
f.innerHTML="",b=a.dom.getNode("div",{style:"white-space: normal;text-align:left;font-size: 12px;font-family: '\u5fae\u8f6f\u96c5\u9ed1'","class":"editor",id:"qun-intro","aria-label":"\u7fa4\u7b80\u4ecb",placeholder:"\u8f93\u5165\u8be6\u7ec6\u7b80\u4ecb\uff0c\u8ba9\u5927\u5bb6\u4e86\u89e3\u4f60\u7684\u7fa4"}),b.innerHTML=w,f.appendChild(b),a.e.add(b,"click",function(){a.css.addClass(f,"editing");require(["./RichEditor"],function(a){i.editor=new a({el:document.getElementById("qun-intro"),wordLimit:i.wordMaxLength});
j.enableSaveBtn();i.editor.onChange=function(){setTimeout(function(){r()},200)}})}),require(["./RichEditor"],function(){}),f.appendChild(b);a.css.show(c);ia();F.change(1);d.auth||(a("qun-name").focus(),a("qun-name").select());ja()}}function ka(){var c=a("js-profile-percent-board");a.e.add(c,"mouseenter",function(){console.log("enter!!!!");if(!L)a("js-profile-percent-hint").style.display="inline-block"});a.e.add(c,"mouseleave",function(){a("js-profile-percent-hint").style.display="none"})}function la(){a.oop.addObserver(j,
"editingStatusChange",function(c){c.isEditing||a.oop.notifyObservers(k,"leaveEditing")})}function Y(){l.callClientAPI("OpenModifyHeadWnd",d.gc);e("PROFILE_QHEAD_MODBTN_CLICK")}function Z(){var a={};try{a=JSON.parse(top.external.GetGroupBasicInfo(d.gc+""))}catch(b){a={}}a==null&&(a={});if($)a.head_type=2;var f=o.getModifyField(true);return{head_type:a.head_type,classID:f.classID||d.catId,"class":o.getDetail(),pos:t.getVal(),tags:Array(d.tagNum)}}function aa(){var c=Z(),b=0;head_type=c.head_type;head_type==
2&&(b+=20);u.getItemById(c.classID)&&(b+=20);c.pos&&(b+=10);a.str.byteLen(i.getText(),3)>90&&(b+=20);if((c.tags||[]).length>=4)b+=30;return b}function r(){var c=Z(),b=0,f={head_type:{fullfill:false,wording:"\u4e0a\u4f20\u81ea\u5b9a\u4e49\u7fa4\u5934\u50cf",percent:20},classID:{fullfill:false,wording:"\u5b8c\u5584\u5206\u7c7b",percent:20},"class":{fullfill:false,wording:"\u5b8c\u5584\u5206\u7c7b\u8be6\u60c5",percent:20},pos:{fullfill:false,wording:"\u6dfb\u52a0\u7fa4\u5730\u70b9",percent:10},gIntro:{fullfill:false,
wording:"\u7b80\u4ecb\u8d85\u8fc730\u5b57",percent:20},tags:{fullfill:false,wording:"\u6807\u7b7e\u8d85\u8fc74\u4e2a",percent:30}};head_type=c.head_type;if(head_type==2)b+=20,f.head_type.fullfill=true;if(c.classID!=0&&u.getItemById(c.classID))c["class"]===null?(b+=20,f.classID.fullfill=true,f["class"].fullfill=true):c["class"]?(b+=20,f.classID.fullfill=true,f["class"].fullfill=true):(f.classID.fullfill=true,f["class"].fullfill=false);if(c.pos)b+=10,f.pos.fullfill=true;if(a.str.byteLen(i.getText(),
3)>90)b+=20,f.gIntro.fullfill=true;if((c.tags||[]).length>=4)b+=30,f.tags.fullfill=true;a("js-profile-percent").innerHTML=b+"%";L=true;for(var d in f)if(c=f[d],!c.fullfill){L=false;a("js-profile-wording").innerHTML=c.wording;a("js-profile-next-percent").innerHTML="+"+c.percent+"%";break}}function ma(){for(var c=a.dom.queryClassAll("pair","div",a("base-info")),b=20,f=0,d=c.length;f<d;f++)c[f].style.zIndex=--b}function na(c){c.pos===""&&delete c.pos;d=a.oop.extend(d,c);d.gAdminsName=d.gAdminsName||
{};d.auth=c.auth;d.catId=c.classID;d.desc=a.str.decodeHtml(c["class"]||"");delete d.classID;delete d["class"];if(typeof c.flag=="undefined")switch(a.bom.getHash("role")){case "1":c.flag=3;break;case "2":c.flag=2;break;case "3":c.flag=1;break;case "4":c.flag=0;break;default:c.flag=0}g.setRole(c.flag);d.isSchoolGroup=d.gSpeClass===3;var c=(c=d)||{},b=u.getCatNamePath(c.catId),f;b.length>=2&&(f=b[1]);n.setPseudoAddr(f,c.desc,c.pos)}function oa(){var c=a("qun-loc-value");c&&(a("qun-loc").getElementsByClassName("del"),
a.e.add(c,"click",H=function(b){var f=g.isEditing;a.css.hasClass(b.target,"check")&&t.loadMap(n.useCityName?"":n.pseudoAddr,g.hasPermission("editCat")?1:0,a("profile-map-container"));b=b.target.getAttribute("data-action");b==="view"?(f=g.getRoleType()==="visitor",e("PROFILE_LBS_VIEWBTN_CLICK",{v:f?1:0})):b==="mod"?(f?e("PROFILE_LBS_MODBTN_CLICK@EDIT=1"):e("PROFILE_LBS_MODBTN_CLICK@EDIT=0"),r()):b==="add"?(a.oop.notifyObservers(n,"addLBS"),f?e("PROFILE_LBS_ADDBTN_CLICK@EDIT=1"):e("PROFILE_LBS_ADDBTN_CLICK@EDIT=0")):
b==="del"&&(n.set_lbs_html(c,{canedit:g.hasPermission("editCat")}),t.clearVal(),j.enableSaveBtn(),p.toggle("qun-loc",""),r(),e("PROFILE_LBS_DELBTN_CLICK"))}),a.oop.addObserver(t,"setMap",function(c){if(g.hasPermission("editCat")){var f=a("qun-loc-value"),d=[];c.province&&d.push(c.province);c.city&&d.push(c.city);c.name&&d.push(c.name);n.set_lbs_html(f,{str:a.str.encodeHtml(d.join("-")),canedit:g.hasPermission("editCat")});a.css.addClass(f,"non-empty");a.css.removeClass(f,"warn");j.enableSaveBtn();
p.toggle("qun-loc",d.join());r()}}))}function ja(){B.init(a("tagsContainer"),d);a.oop.addObserver(B,"onTagChange",function(c){d.tagNum=c.total;a.oop.notifyObservers(k,"onTagChange",c);p.toggle("qun-tag",c.total);m&&(c.action=="add"?e("PROFILE_GUIDE_TAG_ADD",{v:g.getRoleType()=="owner"?1:0}):c.action=="del"&&e("PROFILE_GUIDE_TAG_DEL",{v:g.getRoleType()=="owner"?1:0}));c.action=="add"?e("PROFILE_TAG_ADD",{v:h?1:0}):c.action=="del"&&e("PROFILE_TAG_DEL",{v:h?1:0});h?c.action=="add"&&e("PROFILE_CREATE_MOD_TAG",
{v:h?1:0}):c.action=="add"&&e("PROFILE_PRE_CREATE_SAVE_TAG",{v:g.getRoleType()=="owner"?1:0});r()})}function pa(){a.css.addClass(M,"admin");j.init({domRoot:M,gc:d.gc,cltVer:l.getClientVersion()});a.oop.addObserver(j,"confirmSave",function(){ba()});a.oop.addObserver(j,"modifyCheckerRequest",function(c){var b=N();a.oop.notifyObservers(j,"modifyCheckerResponse",{isModify:b,seq:c})});a.oop.addObserver(j,"editBtnClick",function(){e("PROFILE_ACTIONBAR_EDITBTN_CLICK")});a.oop.addObserver(j,"closeBtnClick",
function(){e("PROFILE_ACTIONBAR_CLOSEBTN_CLICK");m?e("PROFILE_GUIDE_CANCEL_CLICK"):h?e("FROM_CREATE_CANCEL_CLICK"):e("FROM_EDIT_CANCEL_CLICK")});a.oop.addObserver(j,"saveBtnClick",function(){e("PROFILE_ACTIONBAR_SAVEBTN_CLICK");if(O){var c=a("share_photo_open").checked;if(P==c&&!m&&!h)return;C.set_group_setting({param:{gc:d.gc,photoflag:c?1:0},succ:function(a){m?c&&e("PROFILE_GUIDE_SHARE_OPEN_SUCC",{v:g.getRoleType()=="owner"?1:0}):(h&&c&&e("PROFILE_GUIDE_CREATE_OPEN_SUCC",{v:g.getRoleType()=="owner"?
1:0}),c&&e("VISITOR_SHARE_ACCESS_SUCC",{v:g.getRoleType()=="owner"?1:0}));top.postMessage(JSON.stringify({event:"OnShareFlagChanged",from:"Profile"}),"*");console.log("set_group_setting succ: "+a)},err:function(a){console.log("set_group_setting err: "+a)}});m||e("VISITOR_SHARE_ACCESS",{v:g.getRoleType()=="owner"?1:0})}m?e("PROFILE_GUIDE_SAVE_CLICK"):h?e("FROM_CREATE_SAVE_CLICK"):e("FROM_EDIT_SAVE_CLICK")})}function qa(){a.e.add(a("share_photo_open"),"change",I=function(){if(!this.checked&&!l.confirm(1,
"\u63d0\u793a","\u975e\u7fa4\u6210\u5458\u5c06\u65e0\u6cd5\u9884\u89c8\u7fa4\u5185\u76f8\u518c\u4e0e\u5171\u4eab").ret)this.checked=true})}function N(){var a=false,b=g.getRoleType();b!=="member"&&b!=="visitor"&&(a=a||A["qun-name"].isModify()||A["qun-intro"].isModify()||o.checkModify());g.hasPermission("editCat")&&(a=a||A["qun-pos"].isModify());return a?1:0}function ca(c,b,f,d){if(a.str.trim(c)===""&&d)return l.showTips(f+"\u4e0d\u80fd\u4e3a\u7a7a"),false;else if(a.str.byteLen(c,3)>b)return l.showTips(f+
"\u6700\u591a"+b/3+"\u4e2a\u6c49\u5b57"),false;return true}function ra(){var c=true,b;if(g.hasPermission("editCat")){(b=a("qun-name"))&&(c=ca(b.value,X,"\u7fa4\u540d\u79f0",true));if(!c)return c;i.isOpen?i.isOutLength()&&(l.showTips("\u7fa4\u4ecb\u7ecd\u6700\u591a"+i.wordMaxLength+"\u4e2a\u5b57"),c=false):(b=a("qun-intro"))&&(c=ca(b.value,da,"\u7fa4\u7b80\u4ecb"));if(!c)return c}return c=c&&o.checkValidation()}function sa(c){var b={};b.gc=d.gc;b.fRemark=0;if(g.hasPermission("editCat"))if(d.gDisable!==
1){b.gName=d.auth?a.str.decodeHtml(d.gName):a("qun-name").value;if(!d.isSchoolGroup&&(b.gIntro=i.substring(y.moblieCode2Text(y.faceCode2MoblieCode(x.decode(i.getText()))),0,da),i.isOpen)){var f=i.getRichText();i.editor||(f=T.filter(i.decodeRichText(f)));b.gRIntro=U.imgs2Code(y.imgs2MoblieCode(f)).replace(/(<a.+?>)|<\/a>/gi,"").replace(/(\r\n|\n|\r)/gm,"")}b.fOthers=1;f=t.getVal();if(d.pos!==f&&(b.fPos=1,f))b.pos=f}else if(f=!d.auth&&a("qun-name").value!==a.str.decodeHtml(d.gName),!f&&!d.isSchoolGroup&&
(f=A["qun-intro"].isModify()),f){l.showTips("\u7fa4\u8d44\u6599\u6682\u65f6\u65e0\u6cd5\u4fdd\u5b58");l.callClientAPI("OnSave",1);return}b=a.oop.extend(b,o.getModifyField());b.classID&&(console.error("Warning: LBS.setPseudoAddr() unexpect call! params.classID="+b.classID),n.setPseudoAddr(b.classID,b["class"]),m&&(console.log("\u5f15\u5bfc-\u7fa4\u5206\u7c7b-\u6539\u53d8\uff01"),e("PROFILE_GUIDE_CAT_MODIFIED",{v:g.getRoleType()=="owner"?1:0})),m&&W&&(console.log("\u5f15\u5bfc-\u7fa4\u5206\u7c7b-\u6539\u53d8\uff01"),
e("PROFILE_GUIDE_CAT_EMPTY_MODIFIED",{v:g.getRoleType()=="owner"?1:0})));var w=0,V=0;N(true)&&(w++,f=A["qun-intro"].isModify(),m&&f&&(console.log("\u7fa4\u7b80\u4ecb\u53d8\u5316\uff01"),e("PROFILE_GUIDE_INTRO_MODIFIED",{v:g.getRoleType()=="owner"?1:0})),m&&J&&f&&(console.log("\u7fa4\u7b80\u4ecb\u53d8\u5316\uff01\u4e14\u539f\u5148\u4e3a\u7a7a\uff01"),e("PROFILE_GUIDE_INTRO_EMPTY_MODIFIED",{v:g.getRoleType()=="owner"?1:0})),m&&p.allPass()&&e("PROFILE_GUIDE_ALL_FULLFILL",{v:g.getRoleType()=="owner"?
1:0}),h&&e("PROFILE_CREATE_SAVE_CLICK",{v:p.allPass()?1:0}),h||(e("PROFILE_PRE_CREATE_SAVE_SUCC_WITH_CHANGE",{v:g.getRoleType()=="owner"?1:0}),p.allPass()&&e("PROFILE_PRE_CREATE_ALL_FULLFILL",{v:g.getRoleType()=="owner"?1:0})),C.set_group_info({param:b,succ:function(f){if(f.ec===20)l.showTips(f.url[0]+"\u94fe\u63a5\u5b58\u5728\u5b89\u5168\u98ce\u9669\uff0c\u65e0\u6cd5\u4fdd\u5b58\u7b80\u4ecb\u5185\u5bb9\u3002");else{b.gName!==d.gName&&(e("PROFILE_MODIFY_QNAME_SUCC",{v:h?1:0}),h?e("PROFILE_CREATE_MOD_NAME"):
e("PROFILE_PRE_CREATE_MOD_NAME",{v:g.getRoleType()=="owner"?1:0}));if(g.hasPermission("editCat")&&d.gDisable!==1){d.gName=a.str.encodeHtml(b.gName);if(!d.isSchoolGroup&&d.gIntro!==b.gIntro)d.gIntro=b.gIntro,e("PROFILE_MODIFY_INTRO_SUCC",{v:h?1:0});if(b.classID!==void 0)h?(d.catId!=b.classID&&e("PROFILE_CREATE_MOD_CAT"),d.desc!=b["class"]&&e("PROFILE_CREATE_MOD_CAT_DETAIL",{v:d.desc==""?1:0})):(!d.catId&&d.catId!=b.classID&&e("PROFILE_PRE_CREATE_ADD_CAT",{v:g.getRoleType()=="owner"?1:0}),d.catId&&
d.catId!=b.classID&&e("PROFILE_PRE_CREATE_MOD_CAT",{v:g.getRoleType()=="owner"?1:0}),!d.desc&&d.desc!=b["class"]&&e("PROFILE_PRE_CREATE_ADD_CAT_DETAIL",{v:g.getRoleType()=="owner"?1:0}),d.desc&&d.desc!=b["class"]&&e("PROFILE_PRE_CREATE_MOD_CAT_DETAIL",{v:g.getRoleType()=="owner"?1:0})),d.desc=b["class"],d.catId=b.classID,o.storeDetail(),e("PROFILE_MODIFY_CAT&DETAIL_SUCC",{v:h?1:0})}if(b.fPos===1)b.pos?d.pos?(e("PROFILE_LBS_MODIFY_SUCC",{v:h?1:0}),h&&e("PROFILE_CREATE_MOD_CAT_LOC",{v:0})):(e("PROFILE_LBS_ADD_SUCC",
{v:h?1:0}),h&&e("PROFILE_CREATE_MOD_CAT_LOC",{v:1})):e("PROFILE_LBS_DEL_SUCC"),d.pos=b.pos,e("PROFILE_LBS_CHANGE_SUCC");--w===0&&(a.report("now"),c&&c())}},err:function(a){V++;if(!(V>1)){var c="",b=1;switch(a.ec){case 11:c="\u7fa4\u5907\u6ce8\u4fee\u6539\u5931\u8d25";break;case 12:c="\u7fa4\u540d\u79f0\u4e2d\u5305\u542b\u654f\u611f\u8bcd";b=2;break;case 13:c="\u7fa4\u4ecb\u7ecd\u4e2d\u5305\u542b\u654f\u611f\u8bcd";b=2;break;case 14:c="\u7fa4\u4ecb\u7ecd\u4e2d\u5305\u542b\u654f\u611f\u8bcd";b=2;break;
case 15:c="\u60a8\u6ca1\u6709\u4fee\u6539\u6743\u9650";break;case 18:c="\u7fa4\u5df2\u7ecf\u88ab\u5220\u9664";break;case 19:c="\u8be6\u60c5\u4e2d\u5305\u542b\u654f\u611f\u8bcd";b=2;break;case 21:c="\u7fa4\u5907\u6ce8\u5305\u542b\u654f\u611f\u8bcd";b=2;break;default:c="\u4fdd\u5b58\u51fa\u9519\u4e86"}l.showTips(c,b);l.callClientAPI("OnSave",1)}}}))}function ba(c){window.DEBUG||c||l.callClientAPI("IsSelfOnline")?ra()&&sa(function(){l.callClientAPI("OnSave",0);a.oop.notifyObservers(k,"setGrpInfoSucc");
j.stopEditing()}):l.showTips("\u60a8\u5df2\u7ecf\u5904\u4e8e\u79bb\u7ebf\u72b6\u6001\uff0c\u8bf7\u4e0a\u7ebf\u540e\u518d\u6b21\u5c1d\u8bd5")}var ta=function(a){var b={updateAvatar:function(){console.warn("fake updateAvatar calling!");fa({type:"error",msg:"profile\u83b7\u53d6top\u7684Util\u51fa\u9519!(profile.js)"})}};return a&&"updateAvatar"in a?a:(a=top.Util||{})&&"updateAvatar"in a?a:b}(q),q=function(){var c=l.getClientVersion();return function(b){var f={flag1:d.gc,ver:c};if(typeof b==="object"&&
!("v"in b)&&"aId"in b)b=a.bom.getHash("from"),f.v=b&&b==="create"?1:0;return f}}(),e=a.report.ReportFactory({config:{PROFILE_GUIDE_CAT_EMPTY_MODIFIED:{aId:1124},PROFILE_GUIDE_CAT_MODIFIED:{aId:1125},PROFILE_GUIDE_INTRO_MODIFIED:{aId:1126},PROFILE_GUIDE_INTRO_EMPTY_MODIFIED:{aId:1127},PROFILE_GUIDE_TAG_ADD:{aId:1128},PROFILE_GUIDE_TAG_DEL:{aId:1129},PROFILE_GUIDE_SHARE_OPEN_SUCC:{aId:1130,mId:354302},PROFILE_GUIDE_CREATE_OPEN_SUCC:{mId:357338},PROFILE_GUIDE_ALL_FULLFILL:{aId:1131,mId:354303},PROFILE_CREATE_MOD_NAME:{aId:1139},
PROFILE_CREATE_MOD_CAT:{aId:1140},PROFILE_CREATE_MOD_CAT_DETAIL:{aId:1141},PROFILE_CREATE_MOD_CAT_LOC:{aId:1142},PROFILE_CREATE_MOD_TAG:{aId:1143},PROFILE_CREATE_SAVE_CLICK:{aId:1144},PROFILE_CREATE_ENTER:{aId:1145},PROFILE_PRE_CREATE_MOD_NAME:{aId:1147},PROFILE_PRE_CREATE_ADD_CAT:{aId:1148},PROFILE_PRE_CREATE_MOD_CAT:{aId:1149},PROFILE_PRE_CREATE_ADD_CAT_DETAIL:{aId:1150},PROFILE_PRE_CREATE_MOD_CAT_DETAIL:{aId:1151},PROFILE_PRE_CREATE_SAVE_TAG:{aId:1152},PROFILE_PRE_CREATE_SAVE_SUCC_WITH_CHANGE:{aId:1153},
PROFILE_PRE_CREATE_ALL_FULLFILL:{aId:1154},PROFILE_PRE_CREATE_ENTER:{aId:1155},PROFILE_GUIDE_SAVE_CLICK:{mId:356035},PROFILE_GUIDE_CANCEL_CLICK:{mId:356036},FROM_EDIT_SAVE_CLICK:{mId:356037},FROM_EDIT_CANCEL_CLICK:{mId:356038},FROM_CREATE_SAVE_CLICK:{mId:356045},FROM_CREATE_CANCEL_CLICK:{mId:356046},VISITOR_SHARE_ACCESS:{aId:1109},VISITOR_SHARE_ACCESS_SUCC:{aId:1110},PROFILE_GET_INFO_ERR:275016,PROFILE_QHEAD_MODBTN_CLICK:{aId:1082},PROFILE_MODIFY_QNAME_SUCC:{aId:1085},PROFILE_TAG_ADD:{aId:1089},PROFILE_TAG_DEL:{aId:1090},
PROFILE_MODIFY_INTRO_SUCC:{mId:242618,aId:1088,v:0},"PROFILE_MODIFY_CAT&DETAIL_SUCC":{mId:242623,aId:1086},"PROFILE_LBS_MODBTN_CLICK@EDIT=1":{aId:1084},"PROFILE_LBS_ADDBTN_CLICK@EDIT=1":{aId:1083},PROFILE_LBS_ADD_SUCC:306908,PROFILE_LBS_MODIFY_SUCC:306910,PROFILE_LBS_DEL_SUCC:306912,PROFILE_LBS_CHANGE_SUCC:{aId:1087},PROFILE_LEAVE_WITH_HUNDRED_PERCENT:{aId:1180}},getDefaultOptFn:q}),ha={},k={};H=void 0;I=void 0;var M,X=30,da=120,h=false,m=false,$=false,ea=0,E=0,O=false,J=false,W=false,P=false,d={};
d.gc=parseInt(a.bom.getHash("groupuin"),10);o.init({getInfoFn:function(a){return k.getQunInfo(a)}});q=function(c,b,f){this.infoId=c;this.text=b;if(f)for(var d in f)f.hasOwnProperty(d)&&(this[d]=typeof f[d]==="function"?a.oop.bind(f[d],this):f[d])};q.prototype.getInfo=function(){return d[this.infoId]};q.prototype.getValue=function(){var c=a(this.iptId);if(c)return c.value};q.prototype.isModify=function(){var a=false,b=this.getInfo(),f=this.getValue();typeof f!=="undefined"&&(a=b!==f);return a};var A=
{"qun-name":new q("gName","\u540d\u79f0",{iptId:"qun-name",getInfo:function(){return a.str.decodeHtml(d[this.infoId])}}),"qun-intro":new q("gIntro","\u7fa4\u7b80\u4ecb",{isModify:function(){if(i.editor)if(i.orgnalValue.rich){var a=i.getRichText().replace(/(<a.+?>)|<\/a>/gi,"").replace(/\n$/,""),b=i.decodeRichText(i.orgnalValue.rich);return a.length==b.length?a!=b:true}else return a=x.decode(i.orgnalValue.text).length,b=i.getText().length,b==0?false:b!==a+1;return i.textArea?i.getTextLength()!==i.orgnalValue.text.length:
false}}),"qun-pos":new q("pos","\u7fa4\u5730\u70b9",{isModify:function(){var a=t.getVal();if(n.get_lbs_str(a)!==n.pseudoAddr||!a&&d.pos)return a!==d.pos}})},i={editor:null,textArea:null,isOpen:true,wordMaxLength:300,orgnalValue:{text:null,rich:null},getText:function(){return this.editor?this.editor.getText():this.textArea?this.textArea.value:this.orgnalValue.text},getRichText:function(){return this.editor?this.editor.getRichText():this.textArea?this.textArea.value:this.orgnalValue.rich},getTextLength:function(){return this.editor?
this.editor.getTextLength():this.textArea?this.textArea.value.length:this.orgnalValue.text.length},isOutLength:function(){return parseInt(this.getTextLength())>this.wordMaxLength},strip:function(a){return!a?"":x.normalText(a).replace(/(\r\n|\n|\r)/gm," ")},decodeRichText:function(a){return U.code2Img(y.moblieCode2Img(y.code2Img(x.decode(a))))},substring:function(a,b,f){for(var d=0,e=0,g=0,g=0;g<a.length;g++)if(a.charCodeAt(g)>255?e+=3:e++,e<=b)d++;else if(e>b+f)break;return a.substring(d,g)}},K=false,
L=false,Q=function(){function c(b){var d=Array.prototype.slice.call(arguments,1);if(d.length){var e={};if(typeof d[0]==="string")e.url=d[0];var g=new Image;a.e.add(g,"error",function(){a.e.remove(g,"error");e.onerror&&e.onerror();c.apply(null,[b].concat(d.slice(1)))});a.e.add(g,"load",function(){a.e.remove(g,"load");e.onload&&e.onload();g.width<=40?(b.setAttribute("width","40"),b.setAttribute("height","40"),a.css.setStyle(b,{marginLeft:"20px",marginTop:"20px"}),a.css.addClass(b.parentNode,"min")):
b&&(b.setAttribute("width","80"),b.setAttribute("height","80"),a.css.setStyle(b,{marginLeft:"0px",marginTop:"0px"}),a.css.removeClass(b.parentNode,"min"));b.src=e.url});g.src=e.url}}return function(b){b?c(a("js-profile-qhead"),"http://3.url.cn/qun/qinfo_v2/modules/profile/img/profile_default_head.png"):ta.updateAvatar({img:a("js-profile-qhead"),onload:function(b){var c=a("profile-qhead");b<=40?a.css.addClass(c,"min"):a.css.removeClass(c,"min")}},true)}}(),ia=function(){var c=null,b=function(b){if(g.isEditing&&
document.activeElement!==c){var d=document.activeElement;if(a.css.hasClass(d,"detail-trigger")){d.dt.show();var e=null;b.shiftKey?(e=d.nextSibling.lastChild,a.css.isShow(e)?a.css.hasClass(e,"no-college-wrap")&&(e=d.nextSibling.childNodes[1]):e=d.nextSibling.firstChild):e=d.nextSibling.firstChild;e.firstChild.focus()}else!a.css.hasClass(d,"title-wrap")&&!D.curFocusInput&&!a.css.hasClass(d.parentNode,"input-wrap")&&(G.hideAll(),D.hideAll());d.tagName==="TEXTAREA"&&d.select();c=document.activeElement}};
return function(){var c=u.getCatNamePath(d.catId),e=a("qun-cat");a("qun-detail");var i=a.dom.queryClass("detail-trigger-ctn","div",e);i&&e.removeChild(i);var h=g.catTrg=new G(e,{tabIndex:"1"});h.$popView.innerHTML='<div class="kk-select" id="category-value"></div><div class="kk-select" id="subcategory-value"></div>';g.bSetDetail=true;var e=c[0],j=new S(e);g.jCat=j;j.arm(a("category-value"));j.render(u.getCatLeaf(0));j.afterSelect(function(){h.fillTriggerContent(j.$title.innerHTML);var b=u.getCatLeaf(j.id);
b.length===0?(k.hideEntry(),h.hide(),o.changeDetailState(),a.css.hasClass(a("qun-detail").lastChild,"detail-trigger-disabled")?a("qun-intro").focus():a("qun-detail").lastChild.firstChild.focus()):(k.render(b),k.selectDefault(),o.disableDetail());p.toggle("qun-cat",j.$title.innerHTML);r()});var k=new S("-");g.jSubcat=k;k.arm(a("subcategory-value"));k.afterSelect(function(){h.hide();h.fillTriggerContent(j.$title.innerHTML+"-"+k.$title.innerHTML);o.changeDetailState();a.css.hasClass(a("qun-detail").lastChild,
"detail-trigger-disabled")?a("qun-intro").focus():(a("qun-detail").lastChild.firstChild.focus(),b({shiftKey:false}));r()});c=c[1];if(e)if(j.set(e),c)k.set(c);else{if(u.getCatLeaf(j.id).length>0)o.storeDetail(j.id,-1,d.desc),g.bSetDetail=false}else g.fakeDesc=d.desc,g.bSetDetail=false,o.disableDetail();a.e.add(document,"keyup",b);a.e.add(document,"click",function(a){b(a);G.hideAll();D.hideAll()});D.getDepModule()}}();k.init=function(c){M=c||document.body;O=false;E=E=0;(c=a.bom.getHash("from"))&&c===
"create"?(h=true,e("PROFILE_CREATE_ENTER")):(h=false,e("PROFILE_PRE_CREATE_ENTER",{v:g.getRoleType()=="owner"?1:0}));m=c&&c==="guide-index"?true:false;c=parseInt(a.bom.getHash("groupuin"),10);isNaN(c)?(a.oop.notifyObservers(k,"beginJump404"),window.location.href="404.html"):(pa(),qa(),ma(),ka(),F.init([[["document.getElementById('action-edit')",1],["document.querySelectorAll('.aria-block')",1]],[["document.getElementById('qun-name')",1],["document.getElementById('qun-intro')",1],["document.getElementById('action-save')",
2],["document.getElementById('action-close')",2]]]),p.listen("qun-detail",function(){r()}),t.init({getCatFn:function(){return d.catId},encodeFn:function(a){return R.urlencode(a)}}),la(),h||m?P=a("share_photo_open").checked=1:C.get_group_setting({type:"GET",param:{gc:c},succ:function(b){a("share_photo_open").checked=!!b.share;P=!!b.share},err:function(){}}),C.get_group_info({type:"GET",timeout:[3E3,function(){a.oop.notifyObservers(k,"dataTimeout")}],param:{gc:c,t:"basic"},succ:function(b){i.orgnalValue.text=
b.gIntro;i.orgnalValue.rich=x.decodeForMobile(b.gRIntro);na(b);oa();ga();a.e.trigger(a("action-edit"),"click");a.oop.notifyObservers(k,"dataLoaded");(function(){s.pageReady=(new Date).getTime();if(Math.random()>0.5)(new Image).src="http://isdspeed.qq.com/cgi-bin/r.cgi?flag1=7809&flag2=1&flag3=36"+s.getInterval("htmlStart","htmlEnd",7)+s.getInterval("htmlStart","jsloaded",8)+s.getInterval("htmlStart","pageReady",9);var a=g.getRoleType()==="visitor";e("PROFILE_PV",{v:a?1:0})})();O=true;if((h||m)&&b.classID!=
10010&&b.classID!=10012&&b.classID!=10011)a("share_photo_open").checked=1;a.css.show(a("photo-share-container"));d.tagNum=(b.tags||[]).length;setTimeout(function(){r()},10);ea=aa();s.push("profile_click_edit","init_end");s.report2("flag1=7809&flag2=1&flag3=56","profile_click_edit",{init_end:"20",init_start:"19"})},err:function(b){switch(b.ec){case 1:a.oop.notifyObservers(k,"notLogin");break;default:a.oop.notifyObservers(k,"loadDataError")}e("PROFILE_GET_INFO_ERR")}}),Q(h),a.e.add(a("js-profile-changehead"),
"click",Y))};k.hide=function(){g.isEditing=false;E=aa();ea!=100&&E==100&&e("PROFILE_LEAVE_WITH_HUNDRED_PERCENT");a.e.remove(a("js-profile-changehead"),"click",Y);var c=a("qun-loc-value");c&&a.e.remove(c,"click",H);a.oop.removeObserver(t,"setMap");a.oop.removeObserver(j,"confirmSave");a.oop.removeObserver(j,"modifyCheckerRequest");a.oop.removeObserver(j,"editBtnClick");a.oop.removeObserver(j,"closeBtnClick");a.oop.removeObserver(j,"saveBtnClick");a.e.remove(a("qun-intro"),"click");a.css.removeClass(a("intro-wrap"),
"editing");i.editor&&i.editor.destroy();i.editor=null;i.textArea=null;a("qun-intro").innerHTML="";B.destroy();a.oop.removeObserver(B,"onTagChange");a.e.remove(a("share_photo_open"),"change",I);j.destroy();a.oop.removeObserver(j,"editingStatusChange")};k.getQunInfo=function(a){return d[a]};k.tryToLeave=function(){return j.tryToLeave()};k.saveProfile=ba;k.checkModify=function(){return N()};k.refreshGroupHead=Q;k.changeGroupHead=function(){$=true;Q();r()};return window.Profile=k});
