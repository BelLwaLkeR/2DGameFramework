// Grayscale

struct PS_INPUT{
    float4 DiffuseColor       : COLOR0 ;
    float4 SpecularColor      : COLOR1 ;
    float2 TextureCoord0      : TEXCOORD0 ;
    float2 TextureCoord1      : TEXCOORD1 ;
};

struct PS_OUTPUT{
    float4 Output             : COLOR ;
};

sampler	Texture			: register( s0 );
sampler	BumpMap			: register( s1 );
sampler ReflectionMap	: register( s2 );


float2	textureSize		: register( c0 );
float4	ambientColor	: register( c1 );

int		lightNum		: register( c2 );
float4	lightColor		: register( c3 );
float3	_lightPosition	: register( c4 ); 
float	lightPower		: register( c5 );

float clamp(float value, float _min, float _max) {
	return min(max(value, _min), _max);
}

float clamp0to1(float value) {
	return clamp(value, 0, 1);
}

PS_OUTPUT main(PS_INPUT PSInput){	
1	PS_OUTPUT output;
	float	correctionDefuseLength	=  1.2f;
	float	offsetDefuseLightPower	=  1.5f;
	float	correctionAmbientPower	=  2.0f;
	float	correctionSpecularPower	= 10.0f;

	float3	lightPosition = _lightPosition;
	lightPosition.y			*= -1;
	float3	texPosition		= float3(PSInput.TextureCoord1.x, PSInput.TextureCoord1.y, 0);
	float4	textureColor	= tex2D(Texture, PSInput.TextureCoord0);
	float4	bumpMapColor	= normalize(tex2D(BumpMap, PSInput.TextureCoord0) * 2 - 1);
	float4	refrectMap		= tex2D(ReflectionMap, PSInput.TextureCoord0);
	float	lngth			= length(lightPosition);
	float	N				= dot(normalize(lightPosition), bumpMapColor.rgb);
	float4	ambient			= float4(ambientColor.x, ambientColor.y, ambientColor.z, 1) * refrectMap.r;

	float4	defuse			= N * lightColor * (1-(min(lngth * correctionDefuseLength, lightPower) /lightPower)) * offsetDefuseLightPower * refrectMap.g;

	float4	specular		= exp(-pow(1 - N, 2) / (0.05)) * lightColor * refrectMap.b * correctionSpecularPower / (lngth/12 + 0.00001);
	textureColor.rgb		= max(min(textureColor.rgb * (max(defuse, ambient) + specular), 1.f), 0.f);

	output.Output			= textureColor;
	return output;
}
