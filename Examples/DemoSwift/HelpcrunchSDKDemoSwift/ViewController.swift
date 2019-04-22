import UIKit
import HelpCrunchSDK

class ViewController: UIViewController {
    
    @IBOutlet weak var logoutButton: UIButton!
    
    @IBAction func buttonLaunchTouched(_ sender: UIButton) {
        HelpCrunch.show(from: self) { (error) in
            print("HelpCrunch is on screen")
        }
    }
    
    @IBAction func buttonSetDefaultThemeTouched(_ sender: UIButton) {
        HelpCrunch.bindTheme(HelpCrunch.defaultTheme())
    }
    
    @IBAction func buttonSetDarkThemeTouched(_ sender: UIButton) {
        HelpCrunch.bindTheme(HelpCrunch.darkTheme())
    }
    
    @IBAction func buttonSetCustomThemeTouched(_ sender: UIButton) {
        let theme = HelpCrunch.defaultTheme()!
        
        theme.mainColor = UIColor(red: 0.38, green: 0.84, blue: 0.52, alpha: 1.0)
        
        theme.sendButtonText = "Hear me saying!";
        theme.sendButtonColor = UIColor.white
        
        theme.chatBackgroundColor = UIColor(red: 0.22, green: 0.3, blue: 0.38, alpha: 1.0)
        
        theme.messageIncomingBubbleColor = UIColor(red: 0.92, green: 0.87, blue: 0.68, alpha: 1.0)
        theme.messageOutgoingBubbleColor = UIColor(red: 0.88, green: 0.19, blue: 0.19, alpha: 1.0)
        
        theme.inputBackgroundColor = UIColor(red: 0.09, green: 0.09, blue: 0.15, alpha: 1.0)
        theme.inputTextFieldBackgroundColor = UIColor(red: 0.3, green: 0.3, blue: 0.5, alpha: 1.0)
        theme.inputTextFieldFontColor = UIColor.white
        
        theme.keyboardAppearance = .dark
        
        HelpCrunch.bindTheme(theme)
    }
    
    @IBAction func buttonLogoutTouched(_ sender: UIButton) {
        view.isUserInteractionEnabled = false
        
        logoutButton.setTitle("Please wait", for: .normal)
        
        HelpCrunch.logout { (error) in
            self.view.isUserInteractionEnabled = true
            
            self.logoutButton.setTitle("Logout", for: .normal)
        }
    }
}

