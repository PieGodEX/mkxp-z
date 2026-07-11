
uniform sampler2D texture;

varying vec2 v_texCoord;
uniform lowp vec4 colormask;

void main()
{
    vec4 frag = texture2D(texture, v_texCoord);
    if(all(equal(frag.rgb, colormask.rgb))) frag.a = 0.0;
	gl_FragColor = frag;
}