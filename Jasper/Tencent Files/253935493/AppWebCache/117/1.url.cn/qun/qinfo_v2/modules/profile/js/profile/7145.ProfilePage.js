(function(f,e){typeof define==="function"&&define.amd?define(["async"],e):f.ProfilePage=e(f.Async)})(this,function(f){function e(){var a=document.getElementById("profileLayer");return a&&a.style.display==="block"}function i(){var a=document.getElementById("profileLoading");if(!a){var b=document.getElementById("profileLayer");if(!b)return;a=document.createElement("div");a.className="profile_loading";a.innerHTML='<div class="profile_loading_inner"><img src="http://3.url.cn/qun/qinfo_v2/modules/common/img/loading.gif" /><div tabIndex="0">\u6b63\u5728\u52a0\u8f7d\u6570\u636e\uff0c\u8bf7\u7a0d\u5019...</div></div>';
a.id="profileLoading";b.appendChild(a)}a.style.display="block";return a}function g(){var a=document.getElementById("profileLoading");if(a)a.style.display="none"}function j(){var a=function(a,c){console.debug("[registerClientApi]"+a+":"+c);window[a]=function(a){var b=document.getElementById("profileFrame").src.match(/^http:\/\/[\w\.]+\//ig);document.getElementById("profileFrame").contentWindow.postMessage('{"callBackName":"'+c+'","data":"'+encodeURIComponent(a)+'"}',b)}};window.addEventListener("message",
function(b){var c=eval("("+b.data+")"),b=b.origin;if(!(b!=="http://qqun.qq.com"&&b!=="http://qinfo.clt.qq.com")&&(c.fn&&a(c.apiName,c.callBackName),c.variable))window[c.variable]=c.value})}var d={},h=true;window.addEventListener("message",function(a){a=eval("("+a.data+")");if(a.from==="Profile")switch(a.event){case "dataLoaded":console.info("ProfilePage: handle event dataloaded!");break;case "beginJump404":console.info("ProfilePage: handle event beginJump404!");break;case "notLogin":console.info("ProfilePage: handle event notLogin!");
break;case "notLogin":console.info("ProfilePage: handle event notLogin!");break;case "destroy":console.info("ProfilePage: handle event destroy!");d.destroy();break;case "setGrpInfoSucc":console.info("ProfilePage: handle event setGrpInfoSucc!");window.postMessage("{'from':'ProfilePage','event':'setGrpInfoSucc'}","http://qinfo.clt.qq.com");break;case "onTagChange":console.info("ProfilePage: handle event onTagChange!"),window.postMessage(JSON.stringify({from:"ProfilePage",event:"onTagChange",data:a.data}),
"http://qinfo.clt.qq.com")}else if(a.from==="Index")switch(a.event){case "OnGroupHeadChanged":console.info("ProfilePage: handle event OnGroupHeadChanged!"),e()&&Profile.changeGroupHead()}});d.init=function(){TRecord.push("profile_click_edit","base");h&&(j(),window.postMessage("{'from':'ProfilePage','event':'registerClientApi','apiName':'saveProfile'}","http://qinfo.clt.qq.com"),window.postMessage("{'from':'ProfilePage','event':'registerClientApi','apiName':'checkModify'}","http://qinfo.clt.qq.com"),
h=false);i();document.getElementById("profileLayer").style.display="block";window.postMessage("{'from':'ProfilePage','event':'afterShow'}","http://qinfo.clt.qq.com");f.parallel([function(a){require(["profileIndex"],function(b){console.log("profileIndex loaded!");a(null,b)})},function(a){LoadCSS.load("http://2.url.cn/qun/qinfo_v2/modules/profile/css/387c.master.css",function(){g();a(null)})}],function(a,b){TRecord.push("profile_click_edit","init_start");b[0].init();g()});window.postMessage("{'from':'ProfilePage','event':'registerClientApi','apiName':'saveProfile'}",
"http://qinfo.clt.qq.com");window.postMessage("{'from':'ProfilePage','event':'registerClientApi','apiName':'checkModify'}","http://qinfo.clt.qq.com");window.postMessage("{'from':'ProfilePage','event':'registerClientApi','apiName':'saveModify'}","http://qinfo.clt.qq.com")};d.destroy=function(){g();document.getElementById("profileLayer").style.display="none";var a=Profile;typeof a==="object"&&a.hide();window.postMessage("{'from':'ProfilePage','event':'afterClose'}","http://qinfo.clt.qq.com")};d.isShow=
e;d.canLeave=function(){Profile.tryToLeave()};d.checkModify=function(){console.info("ProfilePage.checkModify() is calling");if(!e())return false;var a=Profile;return typeof a==="object"?a.checkModify():(console.warn("ProfilePage<fn:_checkModify>: isShow is true, but getProfileObject return not an object!"),false)};d.saveProfile=function(a){console.info("ProfilePage.saveProfile("+a+") is calling");var b=Profile;typeof b==="object"?b.saveProfile(a):console.warn("ProfilePage<fn:_saveProfile>: getProfileObject return not an object!")};
return window.ProfilePage=d});