// this file is generated via daScript automatic C++ binder
// all user modifications will be lost after this file is re-generated

struct imnodes_IO_EmulateThreeButtonMouse_GeneratedAnnotation : ManagedStructureAnnotation<imnodes::IO::EmulateThreeButtonMouse> {
	imnodes_IO_EmulateThreeButtonMouse_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("EmulateThreeButtonMouse", ml, "imnodes::IO::EmulateThreeButtonMouse") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(modifier)>("modifier","modifier");
	}
};

struct imnodes_IO_LinkDetachWithModifierClick_GeneratedAnnotation : ManagedStructureAnnotation<imnodes::IO::LinkDetachWithModifierClick> {
	imnodes_IO_LinkDetachWithModifierClick_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("LinkDetachWithModifierClick", ml, "imnodes::IO::LinkDetachWithModifierClick") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(modifier)>("modifier","modifier");
	}
};

struct imnodes_IO_GeneratedAnnotation : ManagedStructureAnnotation<imnodes::IO> {
	imnodes_IO_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("IO", ml, "imnodes::IO") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(emulate_three_button_mouse)>("emulate_three_button_mouse","emulate_three_button_mouse");
		addField<DAS_BIND_MANAGED_FIELD(link_detach_with_modifier_click)>("link_detach_with_modifier_click","link_detach_with_modifier_click");
		addField<DAS_BIND_MANAGED_FIELD(alt_mouse_button)>("alt_mouse_button","alt_mouse_button");
	}
};

struct imnodes_Style_GeneratedAnnotation : ManagedStructureAnnotation<imnodes::Style> {
	imnodes_Style_GeneratedAnnotation(ModuleLibrary & ml) : ManagedStructureAnnotation ("Style", ml, "imnodes::Style") {
	}
	void init () {
		addField<DAS_BIND_MANAGED_FIELD(grid_spacing)>("grid_spacing","grid_spacing");
		addField<DAS_BIND_MANAGED_FIELD(node_corner_rounding)>("node_corner_rounding","node_corner_rounding");
		addField<DAS_BIND_MANAGED_FIELD(node_padding_horizontal)>("node_padding_horizontal","node_padding_horizontal");
		addField<DAS_BIND_MANAGED_FIELD(node_padding_vertical)>("node_padding_vertical","node_padding_vertical");
		addField<DAS_BIND_MANAGED_FIELD(node_border_thickness)>("node_border_thickness","node_border_thickness");
		addField<DAS_BIND_MANAGED_FIELD(link_thickness)>("link_thickness","link_thickness");
		addField<DAS_BIND_MANAGED_FIELD(link_line_segments_per_length)>("link_line_segments_per_length","link_line_segments_per_length");
		addField<DAS_BIND_MANAGED_FIELD(link_hover_distance)>("link_hover_distance","link_hover_distance");
		addField<DAS_BIND_MANAGED_FIELD(pin_circle_radius)>("pin_circle_radius","pin_circle_radius");
		addField<DAS_BIND_MANAGED_FIELD(pin_quad_side_length)>("pin_quad_side_length","pin_quad_side_length");
		addField<DAS_BIND_MANAGED_FIELD(pin_triangle_side_length)>("pin_triangle_side_length","pin_triangle_side_length");
		addField<DAS_BIND_MANAGED_FIELD(pin_line_thickness)>("pin_line_thickness","pin_line_thickness");
		addField<DAS_BIND_MANAGED_FIELD(pin_hover_radius)>("pin_hover_radius","pin_hover_radius");
		addField<DAS_BIND_MANAGED_FIELD(pin_offset)>("pin_offset","pin_offset");
		addField<DAS_BIND_MANAGED_FIELD(flags)>("flags","flags");
		addField<DAS_BIND_MANAGED_FIELD(colors)>("colors","colors");
	}
};

