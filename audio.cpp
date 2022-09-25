#include <stdio.h>
#include <alc.h>
#include <al.h>

#include "audio.h"

#pragma commnet(lib, "OpenAL32.lib");

static ALuint sid;


int audioInit() {
	ALCdevice* device = alcOpenDevice(NULL);

	if (!device) {
		return -1;
	}

	ALCcontext* context = alcCreateContext(device, NULL);
	if (!context) {
		return -1;
	}

	alcMakeContextCurrent(context);

	// バッファ作成
	ALuint bid;
	alGenBuffers(1, &bid);

	// 仮データ
	unsigned char data[] = { 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

	alBufferData(bid, AL_FORMAT_MONO8, data, sizeof data, sizeof(data) * 440);

	alGenSources(1, &sid);

	alSourcei(sid, AL_BUFFER, bid);
	alSourcei(sid, AL_LOOPING, AL_TRUE);

	// 音を控える
	alSourcef(sid, AL_GAIN, .1f);

	return 0;
}

void audioPlay() {
	alSourcePlay(sid);

}

void audioStop() {
	alSourceStop(sid);
}
