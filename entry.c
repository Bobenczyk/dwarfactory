
int entry(int argc, char **argv) {
	
	window.title = STR("DwarFactory!");
	window.scaled_width = 1280; // We need to set the scaled size if we want to handle system scaling (DPI)
	window.scaled_height = 720; 
	window.x = 200;
	window.y = 90;
	window.clear_color = hex_to_rgba(0x202028ff);

	float64 start = os_get_current_time_in_seconds();
	// float64 last_time = os_get_current_time_in_seconds();
	while (!window.should_close) {
		float64 now = os_get_current_time_in_seconds();
		// if ((int)now != (int)last_time) log("%.2f FPS\n%.2fms", 1.0/(now-last_time), (now-last_time)*1000);
		// last_time = now;
		
		reset_temporary_storage();
		
		os_update();

		Matrix4 player_xform = m4_scalar(1.0);
		player_xform         = m4_rotate(player_xform, v3(.8f, .3f, 1.7f), (f32)now*36.0f);
		player_xform         = m4_translate(player_xform, v3(sin(now)*((now - start)*(now - start)), cos(now)*((now - start)*(now - start)), 0.0f));
		draw_rect_xform(player_xform, v2(.5f, .5f), COLOR_GREEN);
		
		// draw_rect(v2(sin(now), -.8), v2(.5, .25), COLOR_RED);
		
		// float aspect = (f32)window.width/(f32)window.height;
		// float mx = (input_frame.mouse_x/(f32)window.width  * 2.0 - 1.0)*aspect;
		// float my = input_frame.mouse_y/(f32)window.height * 2.0 - 1.0;
		
		// draw_line(v2(-.75, -.75), v2(mx, my), 0.005, COLOR_WHITE);
		
		gfx_update();
	}

	return 0;
}