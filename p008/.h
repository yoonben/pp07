#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"
#include "Player.hpp"
#include "Monster.hpp"
#include "over.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		MConsolRenderer cRenderer;
		chrono::system_clock::time_point startRenderTimePoint;
		chrono::duration<double> renderDuration;
		Player p;
		Monster m;
		over g;
	public:
		MGameLoop() { _isGameRunning = false; }
		~MGameLoop() {}

		void Run()
		{
			_isGameRunning = true;
			Initialize();

			startRenderTimePoint = chrono::system_clock::now();
			while (_isGameRunning)
			{

				Input();
				Update();
				Render();

			}
			Release();
		}
		void Stop()
		{
			_isGameRunning = false;
		}

	private:
		void Initialize()
		{

		}
		void Release()
		{
		}

		void Input()
		{
			if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
			{
				p.isKeyPressed();
			}
			else
			{
				p.isKeyUnpressed();
			}

		}
		void Update()
		{

		}
		void Render()
		{

			cRenderer.Clear();


			cRenderer.MoveCursor(p.x, p.y);
			cRenderer.DrawString("P");
			cRenderer.MoveCursor(m.x, m.y);
			cRenderer.DrawString("¡Ü");


			m.x -= 2;

			if (m.x == 0)
			{
				m.x = 80;

			}
			if (m.x == 18 && p.y == 7)
			{
				cRenderer.MoveCursor(g.x, g.y);
				cRenderer.DrawString("GAME OVER¡Ú");
				_isGameRunning = false;

			}


			cRenderer.MoveCursor(10, 20);


			renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			startRenderTimePoint = chrono::system_clock::now();
			string fps = "FPS : " + to_string(1.0 / renderDuration.count());
			cRenderer.DrawString(fps);

			this_thread::sleep_for(chrono::milliseconds(20));
		}
	};
}


