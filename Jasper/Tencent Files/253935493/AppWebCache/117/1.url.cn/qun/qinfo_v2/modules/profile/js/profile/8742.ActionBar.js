(function(a,c){typeof define==="function"&&define.amd?define(["simple","commonapi"],c):a.ActionBar=c(a.$)})(this,function(a,c){var b={},e=function(){var d=0,c;return{request:function(e){d++;c=function(a,b){d===b&&(e(a),c=void 0)};a.oop.notifyObservers(b,"modifyCheckerRequest",d)},registry:function(){a.oop.addObserver(b,"modifyCheckerResponse",function(a){typeof c==="function"&&c(a.isModify,a.seq)})},unregistry:function(){a.oop.removeObserver(b,"modifyCheckerResponse")}}}(),f=function(){b.startEditing();
a.oop.notifyObservers(b,"editBtnClick")},g=function(){a.oop.notifyObservers(b,"closeBtnClick");b.tryToLeave()},h=function(){e.request(function(c){c?a.oop.notifyObservers(b,"confirmSave"):b.stopEditing()});a.oop.notifyObservers(b,"saveBtnClick")};b.init=function(){e.registry();a.e.add(a("action-edit"),"click",f);a.e.add(a("action-close"),"click",g);a.e.add(a("action-save"),"click",h)};b.tryToLeave=function(){e.request(function(d){d?(d=c.confirm(1,"\u7fa4\u8d44\u6599\u5361","\u60a8\u5df2\u5bf9\u8d44\u6599\u505a\u4e86\u4fee\u6539\uff0c\u662f\u5426\u4fdd\u5b58\uff1f"))&&
d.ret?a.oop.notifyObservers(b,"confirmSave"):b.stopEditing():b.stopEditing()})};b.startEditing=function(){a.css.updateClass(document.body,"editing","reading");a.oop.notifyObservers(b,"editingStatusChange",{isEditing:true})};b.disableSaveBtn=function(){a("action-save").setAttribute("disabled","disabled")};b.enableSaveBtn=function(){a("action-save").removeAttribute("disabled")};b.stopEditing=function(){a.oop.notifyObservers(b,"editingStatusChange",{isEditing:false})};b.destroy=function(){e.unregistry();
a.e.remove(a("action-edit"),"click",f);a.e.remove(a("action-close"),"click",g);a.e.remove(a("action-save"),"click",h)};return b});