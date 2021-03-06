/** 
 * @file class1\lighting\lightFullbrightAlphaMaskF.glsl
 *
 * $LicenseInfo:firstyear=2011&license=viewerlgpl$
 * Second Life Viewer Source Code
 * Copyright (C) 2011, Linden Research, Inc.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation;
 * version 2.1 of the License only.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 * 
 * Linden Research, Inc., 945 Battery Street, San Francisco, CA  94111  USA
 * $/LicenseInfo$
 */

#ifdef DEFINE_GL_FRAGCOLOR
out vec4 frag_color;
#else
#define frag_color gl_FragColor
#endif

uniform float minimum_alpha;
uniform float texture_gamma; // either 1.0 or 2.2; see: "::TEXTURE_GAMMA"

// render_hud_attachments() -> HUD objects set LLShaderMgr::NO_ATMO; used in LLDrawPoolAlpha::beginRenderPass()
uniform int no_atmo;

vec3 fullbrightAtmosTransport(vec3 light);
vec3 fullbrightScaleSoftClip(vec3 light);

VARYING vec4 vertex_color;
VARYING vec2 vary_texcoord0;

void fullbright_lighting()
{
	vec4 color = diffuseLookup(vary_texcoord0.xy);
	
	if (color.a < minimum_alpha)
	{
		discard;
	}

	color *= vertex_color;

	color.rgb = pow(color.rgb, vec3(texture_gamma));

	// SL-9632 HUDs are affected by Atmosphere
	if (no_atmo == 0)
	{
		color.rgb = fullbrightAtmosTransport(color.rgb);
		color.rgb = fullbrightScaleSoftClip(color.rgb);
	}

	//*TODO: Are we missing an inverse pow() here?
	// class1\lighting\lightFullbrightF.glsl has:
    //     color.rgb = pow(color.rgb, vec3(1.0/texture_gamma));

	frag_color = color;
}

