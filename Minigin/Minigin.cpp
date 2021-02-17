#include "MiniginPCH.h"
#include "Minigin.h"
#include <chrono>
#include <thread>
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include <SDL.h>
#include "TextObject.h"
#include "GameObject.h"
#include "Scene.h"
#include "FPSComponent.h"
#include "TextureComponent.h"

using namespace std;
using namespace std::chrono;

const static float g_TimeStep{0.016f};

void dae::Minigin::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(m_Window);
}

void dae::Minigin::LoadGame() const
{
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	// setting up textures
	auto bgTex{std::make_shared<TextureComponent>(Transform{})};
	bgTex->SetTexture("background.jpg");
	auto logoTex{std::make_shared<TextureComponent>(Transform{216, 180})};
	logoTex->SetTexture("logo.png");

	// add bg
	auto go{std::make_shared<GameObject>()};
	go->AddComponent(bgTex);
	scene.Add(go);

	// add logo
	go = std::make_shared<GameObject>();
	go->AddComponent(logoTex);
	scene.Add(go);

	// add text
	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto to = std::make_shared<TextObject>("Programming 4 Assignment", font);
	to->SetPosition(80, 20);
	scene.Add(to);

	// add fps
	
	//auto fps{std::make_shared<FPSComponent>()};
	//go = std::make_shared<GameObject>();
	//go->AddComponent(fps);
	//scene.Add(go);
	
	/*FPSComponent fps{};
	to = std::make_shared<TextObject>(std::to_string(fps.GetFPS()), font);
	to->SetPosition(30, 70);
	scene.Add(to);*/
}

void dae::Minigin::Cleanup()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}

void dae::Minigin::Run()
{
	Initialize();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

	// main loop
	{
		auto& renderer = Renderer::GetInstance();
		auto& sceneManager = SceneManager::GetInstance();
		auto& input = InputManager::GetInstance();

		bool doContinue = true;
		auto lastTime = high_resolution_clock::now();
		//float lag{};
		while (doContinue)
		{
			const auto currentTime = high_resolution_clock::now();
			const float deltaTime{duration<float>(currentTime - lastTime).count()};
			lastTime = currentTime;
			//lag += deltaTime;
			
			doContinue = input.ProcessInput();
			//while (lag >= g_TimeStep)
			//{
				sceneManager.Update(deltaTime);
			//	lag -= g_TimeStep;
			//}
			renderer.Render();
			
			//auto sleepTime = duration_cast<duration<float>>(currentTime + milliseconds(MsPerFrame) - high_resolution_clock::now());
			//this_thread::sleep_for(sleepTime);
		}
	}

	Cleanup();
}
