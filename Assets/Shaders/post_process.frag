#version 330
layout(location = 0) out vec4 out_color;

in vec2 f_texcoord;

uniform sampler2D uniform_texture;
uniform sampler2D uniform_shadow_map;
uniform sampler2D uniform_cracked_glass_map;
uniform int	uniform_glass_broken = 0;

// for perspective projection only
float linearize(const in float depth)
{
	float near = 0.1;
	float far = 10.0;
    float z = depth * 2.0 - 1.0; // [0, 1] -> [-1, 1]
    return ((2.0 * near * far) / (far + near - z * (far - near))) / far;
}

//#define PREVIEW_SHADOW_MAP
#define CRACKED_GLASS

void main(void)
{
	out_color.xyz = texture2D(uniform_texture, f_texcoord).rgb;

#ifdef PREVIEW_SHADOW_MAP
	out_color = vec4(vec3(linearize(texture2D(uniform_shadow_map, f_texcoord).r)), 1.0);
#elif defined CRACKED_GLASS
	if (uniform_glass_broken != 0) {
		vec4 texture_color = texture2D(uniform_cracked_glass_map, f_texcoord);
		out_color.rgb = texture_color.rgb * texture_color.a + out_color.rgb * (1.0 - texture_color.a);
	}
#endif
}