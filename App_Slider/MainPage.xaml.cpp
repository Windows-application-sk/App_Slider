//
// MainPage.xaml.cpp
// MainPage クラスの実装。
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace App_Slider;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// 空白ページの項目テンプレートについては、https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x411 を参照してください

MainPage::MainPage()
{
	InitializeComponent();
}

// スライダーを動かしている間に表示だけ更新（確定ではない）
void MainPage::ValueSlider_ValueChanged(Object^ sender, Windows::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs^ e)
{
    int currentValue = static_cast<int>(e->NewValue);
    ValueTextBlock->Text = "現在の値：" + currentValue.ToString();
}

// スライダーから指やマウスを離したときに値を確定
void MainPage::ValueSlider_PointerCaptureLost(Object^ sender, PointerRoutedEventArgs^ e)
{
	//メッセージダイアログを表示
	Windows::UI::Popups::MessageDialog^ md = ref new Windows::UI::Popups::MessageDialog(
		L"値が設定されました。"
	);

	//ユーザが応答するまで待機する
	md->ShowAsync();

}

