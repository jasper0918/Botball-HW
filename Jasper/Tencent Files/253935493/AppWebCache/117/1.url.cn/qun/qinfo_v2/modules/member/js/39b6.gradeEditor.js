define("jquery,modules/setting/js/common/client,modules/setting/js/common/cgi,modules/setting/js/common/str,modules/setting/js/common/cookie,modules/common/js/reportPatchJquery,text!../css/member.css".split(","),function(b,l,m,o,C,D,s){var t=b.report.ReportFactory({bId:187,config:{1:{aId:1113},2:{aId:1114},3:{aId:1115},4:{aId:1116},5:{aId:1117},6:{aId:1118}}}),c,f,j,g,h,k=function(){function a(a,d,b){return!d&&!b?e[a]||a:String.fromCharCode(d||b)}function b(a){return g[a]}var d=/&quot;|&lt;|&gt;|&amp;|&nbsp;|&apos;|&#(\d+);|&#(\d+)/g,
u=/['<> "&]/g,e={"&quot;":'"',"&lt;":"<","&gt;":">","&amp;":"&","&nbsp;":" "},c=/\u00a0/g,f=/<br\s*\/?>/ig,i=/\r?\n/g,j=/\s/g,g={},h;for(h in e)g[e[h]]=h;e["&apos;"]="'";g["'"]="&#39;";return{encode:function(a){return a?(""+a).replace(u,b).replace(i,"<br/>").replace(j,"&nbsp;"):""},decode:function(b){return b?(""+b).replace(f,"\n").replace(d,a).replace(c," "):""}}}(),v=function(){m.getLevelName(function(a){f=a.levelname?a.levelname:{lvln1:"\u65b0\u624b",lvln2:"\u521d\u7ea7",lvln3:"\u4e2d\u7ea7",lvln4:"\u9ad8\u7ea7",
lvln5:"\u8d44\u6df1",lvln6:"\u81f3\u5c0a"};j=q(f);c&&c.getNameSuc&&c.getNameSuc(f)})},q=function(a){var b={},d;for(d in a)b[d]=a[d];return b},i=function(){for(var a=1;a<=6;a++)b("#lvln"+a).val(k.decode(f["lvln"+a]));b("#errorBox").hide();b("#editorBox").hide()},n=function(){var a=w(),p={},d=false;if(a)h[a].focus();else{for(a=1;a<7;a++)b("#lvln"+a).val()!==k.decode(f["lvln"+a])&&(p["lvln"+a]=k.decode(b("#lvln"+a).val()),d=true,t(a));d?m.setSetting(p,function(a){a.ec==0?(f=q(j),i(),c&&c.nameChanged&&
c.nameChanged(f)):a.ec==12?b("#errorBox").show().html("\u5185\u5bb9\u5305\u542b\u654f\u611f\u8bcd\uff0c\u8bf7\u91cd\u65b0\u8f93\u5165"):a.ec==13?b("#errorBox").show().html("\u6bcf\u4e2a\u7b49\u7ea7\u5934\u8854\u6bcf\u5929\u6700\u591a\u53ef\u4fee\u6539\u4e09\u6b21 "):b("#errorBox").show().html("\u670d\u52a1\u5668\u7e41\u5fd9")}):i()}},w=function(){for(var a={},b=false,d=0;d<6;d++)if(a[h[d].value]){b=d;break}else a[h[d].value]=1;return b},x=function(){if(!g){for(var a="",c=6;c>=1;c--)a+='<li><input type="text" value="'+
f["lvln"+c]+'" id=lvln'+c+" index="+c+" /></li>";b("body").append('<div id="editorBox">                <div id="editorCloser" class="editorCloser" ></div>                <h3><span>\u7f16\u8f91\u7b49\u7ea7\u5934\u8854</span></h3>                <ul style="background:transparent;">'+a+'</ul>                <div style="color:#96999e;padding-left:42px;position:relative;top:-2px;">\u76f8\u5e94\u7b49\u7ea7\u5934\u8854\u540d\u79f0\u4f1a\u51fa\u73b0\u5728\u7fa4\u804a\u5929\u7a97\u53e3\u4e2d\u3002</div>                <div class="errorBox" id="errorBox">\u8bf7\u5bf9\u4e0d\u540c\u7b49\u7ea7\u4f7f\u7528\u4e0d\u540c\u5934\u8854</div>                <div class="btnBox">                    <input type="button" id="editorSave" value="\u4fdd\u5b58"/><input type="button" id="editorCancel" value="\u53d6\u6d88"/>                </div>            </div>');
g=b("#editorBox");h=g.find("ul li input");b("#editorSave").click(n).bind("keydown",function(a){switch(a.keyCode){case 13:n()}});b("#editorCancel").click(i).bind("keydown",function(a){switch(a.keyCode){case 13:i()}});b("#editorCloser").click(i).bind("keydown",function(a){switch(a.keyCode){case 13:i()}});h.blur(function(){var a=b(this).attr("index"),c=k.encode(this.value),e=j["lvln"+a];if(c==""||this.value.replace(/^\s+|\s+$/ig,"")=="")this.value=k.decode(e),c=e;j["lvln"+a]=c;a={};c=false;for(e=1;e<=
6;e++)if(a[j["lvln"+e]]){c=e;b("#errorBox").show();break}else a[j["lvln"+e]]=1;c||b("#errorBox").hide()}).bind("input",function(){if(b(this).prop("compositionstart")!=true&&o.byteLen(this.value,3)>=6)this.value=o.getMaxlen(this.value,6)}).bind("focus",function(){var a=this;window.setTimeout(function(){a.select()},0)}).bind("keydown",function(a){switch(a.keyCode){case 13:n()}}).bind("compositionstart",function(){b(this).prop("compositionstart",true);console.log("compositionstart")}).bind("compositionend",
function(){b(this).prop("compositionstart",false);console.log("compositionend")});g.click(function(a){a.stopPropagation()})}},r=function(a){x();g.length&&g.show();a.stopPropagation()},y=function(a){a=window.location.hash.match(RegExp("(#|&)"+a+"=([^&]*)(&|$)"));return!a?"":decodeURIComponent(a[2])},z=function(){},A=function(){},B=function(){};return{init:function(a){c=a;a=c.containerId;l.init({getGroupMemberOption:{name:"GetGroupMemberOptionEx",json:true},getGroupMemberInviteOption:"GetGroupMemberInvateOption",
getGroupMsgOption:"GetGroupMsgOption",getGroupVideoOption:"GetGroupVideoOption",isGroupManager:"IsGroupManager",isSetGVideoSvrFlag:"IsSetGVideoSvrFlag",setGroupMemberOption:"SetGroupMemberOption",setGroupMemberOptionEx:"SetGroupMemberOptionEx",setGroupMemberInviteOption:"SetGroupMemberInvateOption",setGroupMsgOption:"SetGroupMsgOption",setGroupVideoOption:"SetGroupVideoOption",onShowTips:"OnShowTips"},{allowConcurrent:false});m.init({getSetting:{url:"/cgi-bin/qun_info/get_group_setting",method:"get"},
setSetting:"/cgi-bin/qun_info/set_group_setting",getLevelName:"/cgi-bin/qun_info/get_group_level_info"},{allowConcurrent:false,defaultParams:{gc:""+(l.getGroupUin()||y("groupuin"))},client:l});b("<style>").html(s).appendTo(b("head"));b("#"+a).unbind("click",r).bind("click",r);b("#editorBox").bind("keypress",z).bind("keyup",A).bind("keydown",B);v()},hide:i}});
