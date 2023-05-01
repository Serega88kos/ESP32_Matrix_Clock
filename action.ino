void action() {
  if (ui.form()) {
    if (ui.form("/wifi")) {
      ui.copyStr("ssid", w.ssid);
      ui.copyStr("pass", w.pass);
      mem1.updateNow();
      ESP.restart();
    }
    // настройки часов
    if (ui.form("/clock")) {
      ui.copyStr("host", c.host);
      ui.copyInt("gmt", c.gmt);
      mem2.updateNow();
    }
    // остальные
    if (ui.form("/other")) {
      ui.copyFloat("cor_tempH", o.cor_tempH);
      ui.copyFloat("cor_tempS", o.cor_tempS);
      ui.copyInt("cor_pres", o.cor_pres);
      ui.copyInt("cor_hum", o.cor_hum);
      ui.copyBool("auto_bright", o.auto_bright);
      ui.copyInt("min_bright", o.min_bright);
      ui.copyInt("max_bright", o.max_bright);
      ui.copyInt("brg", o.brg);
      ui.copyBool("min_max", o.min_max);
      ui.copyBool("sens_bme", o.sens_bme);
      mem3.updateNow();
    }
    // мониторинг
    if (ui.form("/monitoring")) {
      ui.copyBool("Monitoring", m.Monitoring);
      ui.copyInt("delay_narod", m.delay_narod);
      ui.copyBool("nm_tempH", m.nm_tempH);
      ui.copyBool("nm_tempS", m.nm_tempS);
      ui.copyBool("nm_pres", m.nm_pres);
      ui.copyBool("nm_hum", m.nm_hum);
      mem4.updateNow();
    }
  }
  if (ui.click()) {
    if (ui.click("yes_rst")) {
      ESP.restart();
    }
  }
}
