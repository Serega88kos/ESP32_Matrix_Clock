void build() {
  GP.BUILD_BEGIN(portalTheme);
  GP.PAGE_TITLE("Matrix Clock");
  GP.UI_BEGIN("Меню", "/,/wifi,/clock,/other,/monitoring,/ota,/restart", "Начало,Настройки WiFi,Настройки часов,Различные настройки,Мониторинг,Прошивка,Перезагрузка", colorTheme, 400);

  /////WIFI
  if (ui.uri() == "/wifi") {
    GP.FORM_BEGIN("/wifi");
    M_BLOCK(GP_THIN, "", "Настройки WIFI", colorTheme,
            M_TABLE("50px,170px", GP_ALS(GP_LEFT, GP_RIGHT),
                    M_TR(GP.LABEL("SSID"), GP.TEXT("ssid", "", w.ssid, "190px"));
                    M_TR(GP.LABEL("PASS"), GP.PASS_EYE("pass", "", w.pass, "190px"));););
    GP.SUBMIT("Сохранить", colorTheme);
    GP.FORM_END();
  }

  /////CLOCK
  else if (ui.uri() == "/clock") {
    GP.ICON_SUPPORT();
    GP.JQ_SUPPORT();
    GP.JQ_UPDATE_BEGIN(1000);
    M_TABLE("10px,70px,10px", GP_ALS(GP_RIGHT, GP_CENTER, GP_LEFT), "80%",
            M_TR(GP.LABEL(""), GP.LABEL(ntp.timeString()); GP.LABEL(ntp.dateString()); , GP.ICON_BUTTON("sync", "refresh")););
    GP.JQ_UPDATE_END();
    GP.FORM_BEGIN("/clock");
    M_BLOCK(GP_THIN, "", "Настройки часов", colorTheme,
            M_BOX(GP.LABEL("Сервер"); GP.TEXT("host", "", c.host, "200px"););
            M_BOX(GP.LABEL("GMT зона"); GP.NUMBER("gmt", "", c.gmt, "70px");); 
            GP.SPAN("Требуется перезагрузка!"););
    GP.SUBMIT("Сохранить");
    GP.FORM_END();
  }

  /////OTHER
  else if (ui.uri() == "/other") {
    GP.FORM_BEGIN("/other");

     M_BLOCK(GP_THIN, "", "", colorTheme,                     
            M_BOX(GP.LABEL("Датчик BME"); GP.SWITCH("sens_bme", o.sens_bme, colorTheme);););
            
    M_BLOCK(GP_THIN, "", "", colorTheme,
            GP.CHECK("auto_bright", o.auto_bright, colorTheme);
            GP.LABEL("Автояркость");
            M_BOX(GP.LABEL("Инвертировать"); GP.SWITCH("min_max", o.min_max, colorTheme);););

    M_BLOCK(GP_THIN, "", "Яркость", colorTheme,
            M_TABLE("210px,80px", GP_ALS(GP_LEFT, GP_CENTER),
                    M_TR(GP.LABEL("Текущая"), GP.LABEL(String(new_bright)));
                    M_TR(GP.LABEL("Минимальная"), GP.SPINNER("min_bright", o.min_bright, 0, 255, 1, 0, colorTheme, "60px", 0));
                    M_TR(GP.LABEL("Максимальная"), GP.SPINNER("max_bright", o.max_bright, 10, 255, 1, 0, colorTheme, "60px", 0));
                    M_TR(GP.LABEL("Задержка, сек"), GP.SPINNER("brg", o.brg, 0, 30, 1, 0, colorTheme, "60px", 0));););

    M_BLOCK(GP_THIN, "", "Корректировка показаний", colorTheme,
            M_TABLE("110px,30px,80px", GP_ALS(GP_LEFT, GP_RIGHT, GP_CENTER),
                    M_TR(GP.LABEL("Комнатная"), GP.LABEL(String(FtempH)), GP.SPINNER("cor_tempH", o.cor_tempH, -9, 9, 0.1, 1, colorTheme, "60px", 0));
                    M_TR(GP.LABEL("Уличная"), GP.LABEL(String(FtempS)), GP.SPINNER("cor_tempS", o.cor_tempS, -9, 9, 0.1, 1, colorTheme, "60px", 0));
                    M_TR(GP.LABEL("Давление"), GP.LABEL(String(Fpres)), GP.SPINNER("cor_pres", o.cor_pres, -9, 9, 1, 0, colorTheme, "60px", 0));
                    M_TR(GP.LABEL("Влажность"), GP.LABEL(String(hum)), GP.SPINNER("cor_hum", o.cor_hum, -9, 9, 1, 0, colorTheme, "60px", 0));););
    GP.SUBMIT("Сохранить");
    GP.FORM_END();
  }

  /////MONITORING
  else if (ui.uri() == "/monitoring") {
    GP.JQ_SUPPORT();
    MY_JQ_MON();
    GP.FORM_BEGIN("/monitoring");
    M_BLOCK(GP_THIN, "", "", colorTheme,
            GP.LABEL("narodmon.ru");
            GP.BREAK(); GP.LABEL(WiFi.macAddress()););
    M_BLOCK(GP_THIN, "", "", colorTheme,
            GP.CHECK("Monitoring", m.Monitoring, colorTheme);
            GP.LABEL("Включить мониторинг"););
    M_BLOCK(GP_THIN, "", "", colorTheme,
            M_TABLE("210px,80px", GP_ALS(GP_LEFT, GP_CENTER),
                    M_TR(GP.LABEL("Интервал, в сек"), GP.NUMBER("delay_narod", "", m.delay_narod, "70px")););
            M_TABLE("290px", GP_ALS(GP_LEFT),
                    M_TR(GP.SPAN("не менее 300 сек, иначе получите блок!");););
            M_TABLE("290px", GP_ALS(GP_LEFT),
                    M_TR(GP.SPAN("<strong>Исключение: </strong>правило не действует, если есть поддержка сервиса и получены персональные условия."););););
    M_BLOCK(GP_THIN, "", "Отправка показаний датчиков", colorTheme,
            M_BOX(GP.LABEL("Комнатная"); GP.SWITCH("nm_tempH", m.nm_tempH, colorTheme););
            M_BOX(GP.LABEL("Уличная"); GP.SWITCH("nm_tempS", m.nm_tempS, colorTheme););
            M_BOX(GP.LABEL("Давление"); GP.SWITCH("nm_pres", m.nm_pres, colorTheme););
            M_BOX(GP.LABEL("Влажность"); GP.SWITCH("nm_hum", m.nm_hum, colorTheme);););
    GP.SUBMIT("Сохранить", colorTheme);
    GP.FORM_END();
  }
  /////OTA
  else if (ui.uri() == "/ota") {
    M_BLOCK(GP_THIN, "", "Прошивка", colorTheme,
            GP.OTA_FIRMWARE("Выбрать файл", colorTheme);
            GP.LABEL((String)ui.OTA.error()););
  }

  /////RESTART
  else if (ui.uri() == "/restart") {
    M_BLOCK(GP_THIN, "", "Перезагрузить ESP?", colorTheme,
            GP.BUTTON("yes_rst", "Да", "yes_rst", colorTheme, "170px"););
  }

  /////INDEX
  else {
    GP.TITLE("Системная информация.");
    GP.SYSTEM_INFO(Version_Firmware);  // + версия вашей программы (в таблице появится строка Version с указанным текстом), [строка]
  }
  GP.UI_END();
  GP.BUILD_END();
}
