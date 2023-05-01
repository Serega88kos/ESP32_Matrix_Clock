#pragma once
#include "GyverPortal.h"

void MY_JQ_MON() {
  GP.SEND("<script>$(document).ready(function(){$('#Monitoring').click(function(){");
  GP.SEND("if ($(this).is(':checked')){");
  GP.SEND("$('.blockBase').eq(2).show(100);");
  GP.SEND("$('.blockBase').eq(3).show(100);");
  GP.SEND("} else {");
  GP.SEND("$('.blockBase').eq(2).hide(100);");
  GP.SEND("$('.blockBase').eq(3).hide(100);}});");
  GP.SEND("if($('#Monitoring').is(':checked')) {");
  GP.SEND("$('.blockBase').eq(2).show(100);");
  GP.SEND("$('.blockBase').eq(3).show(100);}");
  GP.SEND("else{");
  GP.SEND("$('.blockBase').eq(2).hide(100);");
  GP.SEND("$('.blockBase').eq(3).hide(100);}");  
  GP.SEND("});</script>");
}