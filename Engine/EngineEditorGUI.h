#pragma once
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx12.h"
#include <d3d12.h>
#include <dxgi1_4.h>
#include <tchar.h>

#ifdef _DEBUG
#define DX12_ENABLE_DEBUG_LAYER
#endif

#ifdef DX12_ENABLE_DEBUG_LAYER
#include <dxgidebug.h>
#pragma comment(lib, "dxguid.lib")
#endif

struct FrameContext
{
	ID3D12CommandAllocator* CommandAllocator;
	UINT64                  FenceValue;
};


// Ό³Έν :
class Scene;
class UEngineEditorGUI
{
public:
	// constrcuter destructer
	UEngineEditorGUI();
	~UEngineEditorGUI();

	// delete Function
	UEngineEditorGUI(const UEngineEditorGUI& _Other) = delete;
	UEngineEditorGUI(UEngineEditorGUI&& _Other) noexcept = delete;
	UEngineEditorGUI& operator=(const UEngineEditorGUI& _Other) = delete;
	UEngineEditorGUI& operator=(UEngineEditorGUI&& _Other) noexcept = delete;
	static void GUIRender(Scene* _scene, float _DeltaTime);
	static void GUIInit();
	static void GUIRelease();

protected:

private:
	static ImGuiIO* IOPtr;
	static bool show_demo_window;
	static bool show_another_window;
	static ImVec4 clear_color;

	static bool CreateDeviceD3D(HWND hWnd);
	static void CleanupDeviceD3D();
	static void CreateRenderTarget();
	static void CleanupRenderTarget();
	static void WaitForLastSubmittedFrame();
	static FrameContext* WaitForNextFrameResources();
	static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static HWND hwnd;
	static std::map<std::string, std::shared_ptr<UEngineEditorWindow>> EditorWindows;
};



// Data
static int const                    NUM_FRAMES_IN_FLIGHT = 3;
static FrameContext                 g_frameContext[NUM_FRAMES_IN_FLIGHT] = {};
static UINT                         g_frameIndex = 0;

static int const                    NUM_BACK_BUFFERS = 3;
static ID3D12Device* g_pd3dDevice = nullptr;
static ID3D12DescriptorHeap* g_pd3dRtvDescHeap = nullptr;
static ID3D12DescriptorHeap* g_pd3dSrvDescHeap = nullptr;
static ID3D12CommandQueue* g_pd3dCommandQueue = nullptr;
static ID3D12GraphicsCommandList* g_pd3dCommandList = nullptr;
static ID3D12Fence* g_fence = nullptr;
static HANDLE                       g_fenceEvent = nullptr;
static UINT64                       g_fenceLastSignaledValue = 0;
static IDXGISwapChain3* g_pSwapChain = nullptr;
static HANDLE                       g_hSwapChainWaitableObject = nullptr;
static ID3D12Resource* g_mainRenderTargetResource[NUM_BACK_BUFFERS] = {};
static D3D12_CPU_DESCRIPTOR_HANDLE  g_mainRenderTargetDescriptor[NUM_BACK_BUFFERS] = {};